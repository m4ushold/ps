#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegBeats {
    struct Node { ll mx, mn, sum; };
    const int n, lg, sz;
    vector<Node> tree;
    vector<ll> add, sq;
    SegBeats(int n, const Node &e) : n(n), lg(__lg(n)+1), sz(1<<lg), tree(sz<<1,e), add(sz<<1), sq(sz<<1) {}
    Node mrg(Node a, Node b) { return Node{max(a.mx, b.mx), min(a.mn, b.mn), a.sum+b.sum}; }
    Node& operator [](int i) { return tree[sz|i]; }
    void bld() { for(int i=sz-1;i>=1;i--) tree[i]=mrg(tree[i*2],tree[i*2+1]); }
    void prop(int i, int s, int e) {
        if(!add[i] && !sq[i]) return;
        if(!sq[i]) {
            tree[i].mn+=add[i], tree[i].mx+=add[i];
            tree[i].sum+=(e-s+1)*add[i];
            if(s!=e) add[i*2]+=add[i], add[i*2+1]+=add[i];
            add[i]=0;
            return;
        }   
        tree[i].mn=tree[i].mx=add[i]+sq[i];
        tree[i].sum=(e-s+1)*(add[i]+sq[i]);
        if(s!=e) add[i*2]=add[i], add[i*2+1]=add[i], sq[i*2]=sq[i], sq[i*2+1]=sq[i];
        add[i]=sq[i]=0;
    }
    void rngAdd(int l, int r, ll v) { rngAdd(l,r,v,1,0,sz-1); }
    void rngAdd(int l, int r, ll v, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {add[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        rngAdd(l,r,v,i*2,s,m), rngAdd(l,r,v,i*2+1,m+1,e);
        tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    void rngSq(int l, int r) { rngSq(l,r,1,0,sz-1); }
    void rngSq(int l, int r, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {
            if(floor(sqrt(tree[i].mx))==floor(sqrt(tree[i].mn))) {
                sq[i]=floor(sqrt(tree[i].mx)), prop(i,s,e);
                return;
            } else if(tree[i].mx-1==tree[i].mn) {
                add[i]=floor(sqrt(tree[i].mn))-tree[i].mn, prop(i,s,e);
                return;
            }
        }
        int m=s+e>>1;
        rngSq(l,r,i*2,s,m), rngSq(l,r,i*2+1,m+1,e);
        tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    ll qry(int l, int r) { return qry(l,r,1,0,sz-1); }
    ll qry(int l, int r, int i, int s, int e) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return tree[i].sum;
        int m=s+e>>1;
        return qry(l,r,i*2,s,m)+qry(l,r,i*2+1,m+1,e);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    SegBeats seg(n,{0,0,0});
    for(int i=1,a;i<=n;i++) cin >> a, seg[i]={a,a,a};
    seg.bld();
    int q; cin >> q;
    for(ll i=0,a,b,c,d;i<q;i++) {
        cin >> a >> b >> c;
        if(a==1) cin >> d, seg.rngAdd(b,c,d);
        else if(a==2) seg.rngSq(b,c);
        else cout << seg.qry(b,c) << '\n';
    }
    return 0;
}