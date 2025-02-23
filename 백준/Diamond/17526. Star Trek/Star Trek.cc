#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());

using namespace std;
using ll = long long;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

// rope
#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension

constexpr ll R=1e9, INF=1e18;

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
    void add(ll a, ll b) {upd(line_t(a,b));}
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
} cht;

ll N, A[1<<17], B[1<<17], D[1<<17];

void sol(int tc) {
    cin >> N;
    for(int i=2;i<=N;i++) cin >> D[i], D[i]+=D[i-1];
    for(int i=1;i<N;i++) cin >> B[i] >> A[i];
    cht.add(-A[1], -B[1]);
    for(int i=2;i<N;i++) cht.add(-A[i], -B[i] + cht.qry(D[i]) + A[i]*D[i]);
    cout << -cht.qry(D[N]);
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}