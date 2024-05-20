#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegBeats {
    struct node_t { int a, o, mx; };
    const int n, lg, sz, m=(1<<21)-1;
    const node_t E;
    vector<node_t> tree;
    vector<int> lazy;
    SegBeats(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), E(e), tree(sz<<1,e), lazy(sz<<1) { }
    node_t mrg(node_t a, node_t b) { return {a.a&b.a, a.o|b.o, max(a.mx, b.mx)}; }
    node_t& operator [](int i) { return tree[sz|i]; }
    void bld() { for(int i=sz-1;i>=1;i--) tree[i]=mrg(tree[i*2],tree[i*2+1]); }
    void prop(int i, int s, int e) {
        tree[i].a^=lazy[i], tree[i].o^=lazy[i], tree[i].mx^=lazy[i];
        if(s^e) lazy[i*2]^=lazy[i], lazy[i*2+1]^=lazy[i];
        lazy[i]=0;
    }
    void rngAnd(int l, int r, int x) { rngAnd(l,r,x,1,0,sz-1); }
    void rngAnd(int l, int r, int x, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {
            x|=tree[i].o^m;
            if((~x&(tree[i].a^tree[i].o))==0) {lazy[i]=x^m, prop(i,s,e); return;}
        }
        int m=s+e>>1;
        rngAnd(l,r,x,i*2,s,m), rngAnd(l,r,x,i*2+1,m+1,e);
        tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    void rngOr(int l, int r, int x) { rngOr(l,r,x,1,0,sz-1); }
    void rngOr(int l, int r, int x, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {
            x&=tree[i].a^m;
            if((x&(tree[i].a^tree[i].o))==0) {lazy[i]=x, prop(i,s,e); return;}
        }
        int m=s+e>>1;
        rngOr(l,r,x,i*2,s,m), rngOr(l,r,x,i*2+1,m+1,e);
        tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    int qry(int l, int r) { return qry(l,r,1,0,sz-1); }
    int qry(int l, int r, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return tree[i].mx;
        int m=s+e>>1;
        return max(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    SegBeats seg(n, {(1<<20)-1, 0, 0});
    for(int i=1,a;i<=n;i++) cin >> a, seg[i]={a,a,a};
    seg.bld();
    int q; cin >> q;
    for(int i=0;i<q;i++) {
        int a,l,r,x; cin >> a >> l >> r;
        if(a==1) cin >> x, seg.rngAnd(l,r,x);
        else if(a==2) cin >> x, seg.rngOr(l,r,x);
        else cout << seg.qry(l,r) << '\n';
    }
    return 0;
}