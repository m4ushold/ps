#include <bits/stdc++.h>
using namespace std;

template<typename node_t, typename f_merge>
struct SegmentTree {
    const int n, lg, sz;
    const node_t e;
    vector<node_t> tree;
    f_merge mrg;
    SegmentTree(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), e(e), tree(sz<<1,e) {}
    void upd(int i, const node_t& v) {
        tree[i|=sz]=v;
        while(i/=2) tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    node_t& operator[](int i) { return tree[sz|i]; }
    node_t qry(int l, int r) {
        node_t ll=e,rr=e;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ll=mrg(ll,tree[l++]);
            if(~r&1) rr=mrg(tree[r--],rr);
        }
        return mrg(ll,rr);
    }
};

struct Node { int c, dp, len; };
struct Mrg {
    Node operator() (Node a, Node b) const {
        if(a.len==-1) return b;
        if(b.len==-1) return a;
        return Node{a.c, a.c==b.c && a.dp==a.len ? a.dp+b.dp : a.dp, a.len+b.len };
    }
};

template<typename node_t, typename f_merge>
struct HLD {
    const int n;
    const node_t e;
    vector<int> top, par, dep, sz, in, rin, lf, dp[2];
    vector<vector<int>> graph, tree;
    f_merge mrg;
    SegmentTree<int,plus<int>> c;
    SegmentTree<node_t,f_merge> seg;
    HLD(int n, const node_t &e) : n(n), e(e), c(n,0), seg(n,e), dep(n+1), top(n+1), par(n+1), sz(n+1,1), in(n+1), rin(n+1), graph(n+1), tree(n+1), lf(n+1) {
        for(int i:{0,1}) dp[i].resize(n+1);
    }
    void conn(int u, int v) { graph[u].push_back(v), graph[v].push_back(u); }
    void f(int v=1, int p=-1) {
        for(int i:graph[v]) if(p!=i) tree[v].push_back(i), dep[i]=dep[v]+1, par[i]=v, f(i,v);
    }
    void g(int v=1) {
        for(int &i:tree[v]) {
            g(i), sz[v]+=sz[i];
            if(sz[i]>sz[tree[v][0]]) swap(i,tree[v][0]);
        }
    }
    void h(int v=1) {
        static int ord=0; in[v]=++ord, rin[in[v]]=v;
        for(int i:tree[v]) top[i]= i==tree[v][0] ? top[v] : i, h(i);
        lf[v]=tree[v].size() ? lf[tree[v][0]] : v;
    }
    void bld() { 
        f(), g(), h(top[1]=1);

        for(int i=2;i<=n;i++) if(top[i]==i) dp[0][in[par[i]]]+=sz[i];
        for(int i=1;i<=n;i++) seg.upd(i, Node{0,dp[0][i]+1,dp[0][i]+1});
    }
    int qry1(int u) {
        int color=c[in[u]];
        while(top[u]!=1 && c.qry(in[top[u]],in[u])==(dep[u]-dep[top[u]]+1)*color && c[in[par[top[u]]]]==color) u=par[top[u]];
        int s=0,e=dep[u]-dep[top[u]]+1;
        while(s+1<e) {
            int m=s+e>>1, j=rin[in[u]-m];
            if(c.qry(in[j], in[u]) == (dep[u]-dep[j]+1)*color) s=m;
            else e=m;
        }
        return rin[in[u]-s];
    }
    void upd(int u, int f=1) {
        for(;top[u]!=1;u=par[top[u]]) {
            dp[c[in[top[u]]]][in[par[top[u]]]] -= seg.qry(in[top[u]], in[lf[u]]).dp;
            if(f) c.upd(in[u], 1-c[in[u]]), f=0;
            seg.upd(in[u], Node{c[in[u]], dp[c[in[u]]][in[u]]+1, dp[c[in[u]]][in[u]]+1});
            dp[c[in[top[u]]]][in[par[top[u]]]] += seg.qry(in[top[u]], in[lf[u]]).dp;
        }
        if(f) c.upd(in[u], 1-c[in[u]]);
        seg.upd(in[u], Node{c[in[u]], dp[c[in[u]]][in[u]]+1, dp[c[in[u]]][in[u]]+1});
    }
    int qry(int u) {
        u=qry1(u);
        return seg.qry(in[u], in[lf[u]]).dp;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    HLD<Node,Mrg> tree(n,Node{0,0,-1});
    for(int i=1,s,e;i<n;i++) cin >> s >> e, tree.conn(s,e);
    tree.bld();

    int q; cin >> q;
    for(int i=0,a,b;i<q;i++) {
        cin >> a >> b;
        if(a&1) tree.upd(b);
        else cout << tree.qry(b) << '\n';
    }
    return 0;
}