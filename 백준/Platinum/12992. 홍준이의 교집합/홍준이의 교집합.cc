#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int mod = 1e9+7;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n>>=1;
    }
    return res;
}

ll S[606060], F[202020]={1}, I[202020]={1};

ll ncr(ll n, ll r) {
    return F[n] * I[r] % mod * I[n-r] % mod;
}

void sol(int tc) {
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++) F[i]=F[i-1]*i%mod, I[i] = pw(F[i],mod-2);

    vector<pll> v(n);
    vector<ll> c;
    for(auto &[l,r]:v) cin >> l >> r, c.push_back(l), c.push_back(r), c.push_back(r+1);
    prs(c);
    for(auto &[l,r]:v) {
        l = lower_bound(all(c),l)-c.begin()+1, r = lower_bound(all(c),r)-c.begin()+1;
        S[l]++, S[r+1]--;
    }
    // [l,r)
    ll ans = 0;
    for(int i=1;i<606060;i++) {
        S[i]+=S[i-1];
        if(S[i] >= k) {
            ans += (c[i]-c[i-1]) * ncr(S[i],k) % mod;
            ans %= mod;
        }
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