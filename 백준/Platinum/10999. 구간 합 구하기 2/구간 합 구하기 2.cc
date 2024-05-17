#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename node_t, typename f_merge>
struct LazySegmentTree {
    const int n, lg, sz;
    const node_t E;
    vector<node_t> tree, lazy;
    f_merge mrg;
    LazySegmentTree(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), E(e), tree(sz<<1,e), lazy(sz<<1,e) {}
    node_t& operator [](int i) { return tree[sz|i]; }
    void bld() { for(int i=sz-1;i>=1;i--) tree[i]=mrg(tree[i*2],tree[i*2+1]); }
    void prop(int i, int s, int e) {
        if(lazy[i]==E) return;
        tree[i]+=(e-s+1)*lazy[i];
        if(s!=e) lazy[i*2]+=lazy[i], lazy[i*2+1]+=lazy[i];
        lazy[i]=E;
    }
    void upd(int l, int r, node_t& v) { upd(l,r,v,1,0,sz-1); }
    void upd(int l, int r, node_t& v, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {lazy[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    node_t qry(int l, int r) { return qry(l,r,1,0,sz-1); }
    node_t qry(int l, int r, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return E;
        else if(l<=s && e<=r) return tree[i];
        int m=s+e>>1;
        return mrg(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    LazySegmentTree<ll,plus<ll>> seg(n,0);
    for(int i=1;i<=n;i++) cin >> seg[i];
    seg.bld();
    for(int i=0;i<m+k;i++) {
        ll a,b,c,d; cin >> a >> b >> c;
        if(a&1) cin >> d, seg.upd(b,c,d);
        else cout << seg.qry(b,c) << '\n';
    }
    return 0;
}