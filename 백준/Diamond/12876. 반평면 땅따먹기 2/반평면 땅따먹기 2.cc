#include <bits/stdc++.h>
using namespace std;
using ll=long long;

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
    void upd(line_t v, int i=0, ll s=-R, ll e=R) {
        line_t lo=T[i].v, hi=v;
        if(lo.f(s) > hi.f(s)) swap(lo,hi);
        if(lo.f(e) <= hi.f(e)) {T[i].v=hi; return;}
        ll m=(s+e)>>1;
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
        ll m=(s+e)>>1;
        if(x<=m) res=max(res,qry(x,T[i].l,s,m));
        else res=max(res,qry(x,T[i].r,m+1,e));
        return res;
    }
};

constexpr int sz = 1<<19;
struct SegTree {
    LiChaoTree T[sz<<1];
    void upd(int l, int r, line_t line, int i=1, int s=0, int e=sz-1) {
        if(l<=s && e<=r) {
            T[i].upd(line);
            return;
        }
        if(r<s || e<l) return;

        int m=(s+e)>>1;
        upd(l,r,line,i*2,s,m);
        upd(l,r,line,i*2+1,m+1,e);
    }
    ll qry(int i, ll x) {
        i|=sz;
        ll res=-INF;
        while(i) {
            res=max(res,T[i].qry(x));
            i>>=1;
        }
        return res;
    }
} seg;

void sol(int tc) {
    int n; cin >> n;
    map<int,tuple<line_t,int,int>> m;
    vector<ll> q;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        int op; cin >> op;
        if(op==1) {
            int a,b; cin >> a >> b;
            m[i]={line_t(a,b),cnt+1,n};
        } else if(op==2) {
            int x; cin >> x;
            auto &[line,s,e]=m[x];
            e=cnt;
        } else {
            int x; cin >> x;
            q.push_back(x);
            cnt++;
        }
    }
    for(auto [i,x]:m) {
        auto [line,s,e]=x;
        e = min(e, cnt);
        seg.upd(s,e,line);
    }

    for(int i=1;i<=cnt;i++) {
        ll ans = seg.qry(i,q[i-1]);
        if(ans == -INF) cout << "EMPTY\n";
        else cout << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}