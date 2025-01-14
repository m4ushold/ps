#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<18;
struct Seg {
    ll T[sz<<1];
    void clear() {memset(T, 0, sizeof(T));}
    void build() {for(int i=sz-1;i;i--) T[i]=T[i*2]+T[i*2+1];}
    void update(int i, ll v) {
        T[i|=sz]=v;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
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
    ll queryEdge(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=seg.query(IN[TOP[u]], IN[u]);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=seg.query(IN[u]+1, IN[v]);
        return res;
    }
    ll queryVertex(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=seg.query(IN[TOP[u]], IN[u]);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=seg.query(IN[u], IN[v]);
        return res;
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1,u,v;i<n;i++) cin >> u >> v, tree.connect(u,v);
    tree.build();

    int q; cin >> q;
    for(int i=1,op,a,b,c,d;i<=q;i++) {
        cin >> op;
        if(op==1) {
            cin >> a >> b >> c;
            tree.update(c, 1);
            cout << (tree.queryVertex(a,b)?"NO":"YES") << '\n';
            tree.update(c, 0);
        } else {
            cin >> a >> b >> c >> d;
            if(tree.D[c] > tree.D[d]) swap(c,d);
            tree.update(d, 1);
            cout << (tree.queryEdge(a,b)?"NO":"YES") << '\n';
            tree.update(d, 0);
        }
    }
    return 0;
}