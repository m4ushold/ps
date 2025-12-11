#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, sz;
    vector<S> T;
    segtree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void set(int i, S x) {
        T[i|=sz] = x;
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    void add(int i, S x) {
        T[i|sz] = op(T[i|=sz], x);
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
    int x,y; cin >> x >> y;
    map<pll,vector<pll>> m;
    int n; cin >> n;
    for(ll i=0,xx,yy,h;i<n;i++) {
        cin >> xx >> yy >> h;
        xx-=x, yy-=y;
        ll g=gcd<ll>(xx,yy);
        m[{xx/g,yy/g}].push_back({g,h});
    }
    segtree<ll,op,e> seg(1e6+1);
    ll ans=0;
    for(auto [a,v]:m) {
        sort(all(v));
        ll mx=0;
        for(auto [h,i]:v) {
            ll d = seg.qry(0,i-1)+1;
            mx=max(mx,d);
            seg.add(i,d);
        }
        ans += mx;
        for(auto [h,i]:v) seg.set(i,0);
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