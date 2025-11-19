#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct SegTree {
    int n, sz;
    vector<S> T;
    SegTree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void upd(int i, S x) {
        T[i] = op(x, T[i|=sz]);
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    S qry(int l, int r) {
        S L=e(), R=e();
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) L=op(L,T[l++]);
            if(~r&1) R=op(T[r--],R);
        }
        return op(L,R);
    }
};

ll op(ll a, ll b) {return max(a,b);}
ll e() {return 0;}

void sol(int tc) {
    int n; cin >> n;
    vector<pll> v(n);
    vector<int> h;
    for(auto &[a,b]:v) cin >> a >> b, h.push_back(b);
    prs(h);
    for(auto &[a,b]:v) b = lower_bound(all(h), b)-h.begin();

    SegTree<ll,op,e> seg(n+1);
    prs(v);
    reverse(all(v));

    ll ans=0;
    for(auto [a,b]:v) {
        ll t = seg.qry(0,b)+h[b];
        seg.upd(b, t);
        ans=max<ll>(ans, t);
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}