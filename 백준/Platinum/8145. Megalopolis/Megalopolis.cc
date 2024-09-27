#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename node_t, typename f_merge>
struct SegmentTree {
    const int n, lg, sz;
    const node_t e;
    vector<node_t> tree;
    f_merge mrg;
    SegmentTree(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), e(e), tree(sz<<1,e) {}
    void bld() { for(int i=sz-1;i>=1;i--) tree[i]=mrg(tree[i*2],tree[i*2+1]); }
    void upd(int i, const node_t& v) {
        tree[i|=sz]=v;
        while(i/=2) tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    node_t& operator [](int i) {return tree[sz|i]; }
    node_t qry(int l, int r) const {
        node_t ret=e;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=mrg(tree[l++],ret);
            if(~r&1) ret=mrg(ret,tree[r--]);
        }
        return ret;
    }
};

template<typename node_t, typename f_merge>
struct HLD {
    const int n;
    const node_t e;
    vector<int> top, par, dep, sz, in;
    vector<vector<int>> graph, tree;
    f_merge mrg;
    SegmentTree<node_t,f_merge> seg;
    HLD(int n, const node_t &e) : n(n), e(e), seg(n,e), dep(n+1), top(n+1), par(n+1), sz(n+1,1), in(n+1), graph(n+1), tree(n+1) {}
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
        static int ord=0; in[v]=++ord;
        for(int i:tree[v]) top[i]= i==tree[v][0] ? top[v] : i, h(i);
    }
    void bld() {
        f(), g(), h(top[1]=1);
        for(int i=2;i<=n;i++) seg[i] = 1;
        seg.bld();
    }

    void upd(int u, int x) { seg.upd(in[u],x); }
    node_t qry(int u, int v) {
        node_t res=e;
        for(;top[u]!=top[v];u=par[top[u]]) {
            if(dep[top[u]] < dep[top[v]]) swap(u,v);
            res=mrg(res,seg.qry(in[top[u]], in[u]));
        }
        if(in[u] > in[v]) swap(u,v);
        res=mrg(res,seg.qry(in[u]+1, in[v])); // edge
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n;
    HLD<ll,plus<ll>> tree(n,0);
    for(int i=1,u,v;i<n;i++) cin >> u >> v, tree.conn(u,v);
    tree.bld();

    cin >> q;
    for(int i=0,a,b;i<n+q-1;i++) {
        char c; cin >> c >> a;
        if(c=='W') cout << tree.qry(1,a) << '\n';
        else cin >> b, tree.upd(b,0);
    }
    return 0;
}