#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17;
struct Seg {
    ll T[sz<<1];
    void upd(int i, ll x) {
        T[i|=sz]=x;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    ll qry(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} up, down;

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
    void upd(int u, int s, int t) {
        up.upd(IN[u], s);
        down.upd(IN[u], t);
    }
    int getLCA(int u, int v) {
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
        }
        return D[u] < D[v] ? u : v;
    }
    ll upQry(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=up.qry(IN[TOP[u]], IN[u]);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=up.qry(IN[u]+1, IN[v]);
        return res;
    }
    ll downQry(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=down.qry(IN[TOP[u]], IN[u]);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=down.qry(IN[u]+1, IN[v]);
        return res;
    }
    ll qry(int u, int v) {
        int l=getLCA(u,v);
        return upQry(u,l) + downQry(v,l);
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for(int i=2;i<=n;i++) up.upd(i,1), down.upd(i,1);
    vector<pair<int,int>> edges;
    for(int i=1,u,v;i<n;i++) cin >> u >> v, tree.connect(u,v), edges.emplace_back(u,v);
    tree.build();

    for(int i=0,r,s,t,u,v;i<q;i++) {
        char op; cin >> op;
        if(op=='I') {
            cin >> r >> s >> t;
            auto [x,y]=edges[r-1];
            if(x > y) swap(x,y);
            // x -> y : s, y -> x : t
            if(tree.D[x] > tree.D[y]) tree.upd(x, s, t);
            else tree.upd(y, t, s);
        } else cin >> u >> v, cout << tree.qry(u,v) << '\n';
    }
    return 0;
}