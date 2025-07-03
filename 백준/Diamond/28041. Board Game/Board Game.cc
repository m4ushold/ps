#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll R=1e9, INF=2e18, sz = 1<<17;

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
};

struct {
    LiChaoTree T[sz<<1];
    void upd(int i, line_t v) {
        T[i|=sz].upd(v);
        while(i>>=1) T[i].upd(v);
    }
    int qry(ll x, ll y, int i=1) {
        while(i<sz) {
            if(T[i*2].qry(x) > y) i*=2;
            else i=i*2+1;
        }
        return i^sz;
    }
} seg;

vector<int> A[sz];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t,p; cin >> t;
    vector<pair<ll,ll>> v(t);
    for(auto &[a,b]:v) cin >> a >> b;
    cin >> p;
    for(ll i=1,a,b;i<=p;i++) {
        cin >> a >> b;
        seg.upd(i, line_t(a,b));
    }

    for(int i=0;i<t;i++) {
        auto [x,y]=v[i];
        A[seg.qry(x,y)].push_back(i+1);
    }
    for(int i=1;i<=p;i++) {
        cout << A[i].size() << ' ';
        for(int j:A[i]) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}