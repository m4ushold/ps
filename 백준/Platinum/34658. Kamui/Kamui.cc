#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int mod = 998244353;

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
        T[i|=sz] += x;
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

ll op(ll a, ll b) {return (a+b)%mod;}
ll e() {return 0;}

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n>>=1;
    }
    return res;
}

ll nc2(ll n) {
    if(n<=1) return 0;
    return n*(n-1)%mod*pw(2,mod-2)%mod;
}

void sol(int tc) {
    ll n,q; cin >> n >> q;
    SegTree<ll,op,e> seg(n+1);
    vector<ll> v(n);
    for(ll &i:v) cin >> i, seg.upd(i,1);
    
    ll sum=0, ans=0;
    for(int i=1;i<=n;i++) {
        ll t = seg.qry(i,i);
        ans += sum*t%mod + nc2(t)*nc2(i)%mod;
        ans %= mod;
        sum += t * nc2(i)%mod;
        sum %= mod;
    }

    for(int i=0;i<q;i++) {
        ll x,d; cin >> x >> d;
        x--;
        if(d==1) {
            ans += seg.qry(v[x]+1,n) * v[x] % mod;
            ans %= mod;
        } else {
            ans -= (seg.qry(v[x],n)-1) * (v[x]-1) % mod;
            ans %= mod;
        }

        ans = (ans%mod+mod)%mod;
        cout << ans << endl;
        seg.upd(v[x],-1), seg.upd(v[x]+d,1);
        v[x]+=d;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}