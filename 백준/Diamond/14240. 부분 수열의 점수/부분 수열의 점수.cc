#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll R=2e12, INF=2e18;

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
        ll m=s+e>>1;
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
        ll m=s+e>>1;
        if(x<=m) res=max(res,qry(x,T[i].l,s,m));
        else res=max(res,qry(x,T[i].r,m+1,e));
        return res;
    }
} seg;

ll N, A[202020], S[202020], SS[202020];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i], S[i]=S[i-1]+A[i], SS[i]=SS[i-1]+i*A[i];
    seg.upd(line_t(0,0));

    ll ans=0;
    for(int i=1;i<=N;i++) {
        ans = max(ans, seg.qry(S[i]) + SS[i]);
        seg.upd(line_t(-i, S[i]*i - SS[i]));
    }
    cout << ans;
    return 0;
}