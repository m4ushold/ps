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
        tree[i|=sz]+=v;
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

ll N, C, Q, IN[202020], OUT[202020], D[202020];
vector<int> G[202020];

void dfs(int v, int p=-1) {
    static int cnt=0;
    IN[v]=++cnt;
    for(int i:G[v]) if(p!=i) D[i]=D[v]+1, dfs(i,v);
    OUT[v]=cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    D[C]=1, dfs(C);

    SegmentTree<ll,plus<ll>> seg(N,0);
    cin >> Q;
    for(int i=0,a,b;i<Q;i++) {
        cin >> a >> b;
        if(a==1) seg.upd(IN[b],1);
        else cout << seg.qry(IN[b], OUT[b])*D[b] << '\n';
    }
    return 0;
}