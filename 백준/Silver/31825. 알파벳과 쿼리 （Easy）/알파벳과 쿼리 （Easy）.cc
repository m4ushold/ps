#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename node_t, typename f_merge>
struct LazySegmentTree {
    const int n, lg, sz;
    const node_t E;
    vector<node_t> tree;
    vector<int> lazy;
    f_merge mrg;
    LazySegmentTree(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), E(e), tree(sz<<1,e), lazy(sz<<1,0) {}
    node_t& operator [](int i) { return tree[sz|i]; }
    void bld() { for(int i=sz-1;i>=1;i--) tree[i]=mrg(tree[i*2],tree[i*2+1]); }
    void prop(int i, int s, int e) {
        if(lazy[i]==0) return;
        tree[i].l=(tree[i].l+lazy[i])%26;
        tree[i].r=(tree[i].r+lazy[i])%26;
        if(s!=e) lazy[i*2]+=lazy[i], lazy[i*2+1]+=lazy[i];
        lazy[i]=0;
    }
    void upd(int l, int r, int v) { upd(l,r,v,1,0,sz-1); }
    void upd(int l, int r, int v, int i, int s, int e) {
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

struct Node { int l, r, cnt; };
struct Mrg {
    Node operator() (Node a, Node b) {
        if(a.l<0) return b;
        if(b.l<0) return a;
        return {a.l, b.r, a.cnt+b.cnt+(a.r==b.l ? -1 : 0)};
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    string s; cin >> s;
    LazySegmentTree<Node, Mrg> seg(n,{-1,-1,-1});
    for(int i=0;i<n;i++) seg[i+1]={s[i]-'A',s[i]-'A',1};
    seg.bld();

    for(int i=0,a,l,r;i<q;i++) {
        cin >> a >> l >> r;
        if(a&1) cout << seg.qry(l,r).cnt << '\n';
        else seg.upd(l,r,1);
    }
    return 0;
}