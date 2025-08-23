#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

void sol(int tc) {
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end(),greater<>());
    ll ans=0;
    for(int i=0;i<n;i++) {
        ans += pw(2,n-i-1)*v[i]%mod;
        ans %= mod;
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