#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll R=1e12, INF=2e18;

struct line_t {
    ll a,b;
    line_t(ll a, ll b) : a(a), b(b) {}
    line_t() : a(0), b(-INF) {}
    ll f(ll x) const { return a*x+b; }
};

struct LiChaoTree {
    struct node_t {
        int l, r;
        line_t v;
        node_t() : l(-1), r(-1), v() {}
    };
    vector<node_t> T;
    LiChaoTree() { T.clear(), T.emplace_back(); }
    void upd(line_t v, int i=0, ll s=-R, ll e=R) {
        line_t lo=T[i].v, hi=v;
        if(lo.f(s) > hi.f(s)) swap(lo,hi);
        if(lo.f(e) <= hi.f(e)) {T[i].v=hi; return;}
        int m=s+e>>1;
        if(lo.f(m) < hi.f(m)) {
            T[i].v=hi;
            if(T[i].r == -1) T[i].r=T.size(), T.emplace_back();
            upd(lo, T[i].r, m+1,e);
        } else {
            T[i].v=lo;
            if(T[i].l == -1) T[i].l=T.size(), T.emplace_back();
            upd(hi, T[i].l, s, m);
        }
    }
    ll qry(ll x, int i=0, ll s=-R, ll e=R) {
        ll res=i==-1 ? -INF : T[i].v.f(x);
        if(i==-1 || s==e) return res;
        int m=s+e>>1;
        if(x<=m) res=max(res,qry(x,T[i].l,s,m));
        else res=max(res,qry(x,T[i].r,m+1,e));
        return res;
    }
} seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
	while (q--){
		ll op, a, b; cin >> op;
        if(op&1) cin >> a >> b, seg.upd(line_t(a,b));
        else cin >> a, cout << seg.qry(a) << '\n';
	}
    return 0;
}