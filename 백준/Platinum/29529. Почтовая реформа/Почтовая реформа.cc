#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<18;
struct Seg {
    ll T[sz<<1];
    void update(int i, ll v) {
        T[i|=sz]=v;
        while(i/=2) T[i]=max(T[i*2],T[i*2+1]);
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

struct HLD {
    int TOP[sz], P[sz], D[sz], SZ[sz], IN[sz];
    vector<int> GG[sz], G[sz];
    void connect(int u, int v) {
        GG[u].push_back(v), GG[v].push_back(u);
    }
    void d1(int v=1, int p=-1) {
        for(int i:GG[v]) if(i!=p) G[v].push_back(i), D[i]=D[v]+1, P[i]=v, d1(i,v);
    }
    void d2(int v=1) {
        SZ[v]=1;
        for(int &i:G[v]) {
            d2(i), SZ[v]+=SZ[i];
            if(SZ[i]>SZ[G[v][0]]) swap(i,G[v][0]);
        }
    }
    void d3(int v) {
        static int pv=0; IN[v]=++pv;
        for(int i:G[v]) TOP[i]= (i==G[v][0] ? TOP[v] : i), d3(i);
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
    }
    void update(int v, int x) {
        seg.update(IN[v], x);
    }
    ll query(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res=max(res,seg.query(IN[TOP[u]], IN[u]));
        }
        if(IN[u] > IN[v]) swap(u,v);
        res=max(res,seg.query(IN[u], IN[v]));
        return res;
    }
} tree;

void sol(int tc) {
    int n,q; cin >> n;
    vector<int> h(n);
    for(int &i:h) cin >> i;
    for(int i=2,a,b;i<=n;i++) cin >> a >> b, tree.connect(a,b);
    tree.build();
    for(int i=1;i<=n;i++) tree.update(i,h[i-1]);

    cin >> q;
    for(int i=0,a,b;i<q;i++) {
        char op; cin >> op >> a >> b;
        if(op=='!') tree.update(a,b);
        else cout << tree.query(a,b) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}