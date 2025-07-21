#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;
ll inv;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

inline ll s(ll x) {
    return x*(x-1) % mod * inv % mod;
}

inline ll sum(ll n, ll m) {
    if(n < 0) return 0;
    return ((n/m) * s(m) % mod + s(n%m+1)) % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    ll s = sqrt(n), ans = 0;
    inv = pw(2, mod-2);

    for(ll x=1;x<s;x++) {
        ans = (ans + (n/x)*(x%m) % mod) % mod;
    }

    // n/x == i
    for(ll i=1;i<=n/s;i++) {
        ll r=n/i, l=n/(i+1)+1;
        ll tmp = sum(r,m) - sum(l-1, m) + mod;
        ans = (ans + tmp % mod * i % mod) % mod;
    }
    cout << ans;
    return 0;
}