#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;
ll N, F[1010101], I[1010101], D[1010101];

ll pw(ll a, ll n) {
    ll res = 1;
    if(n<=0) return res;
    while(n) {
        if(n&1) res = res * a % mod;
        a = a*a%mod, n/=2;
    }
    return res;
}

ll ncr(ll n, ll r) {
    return F[n]*I[r]%mod*I[n-r]%mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    int a,b; cin >> a >> b;
    F[0]=1, I[0]=1;
    D[a] = D[b] = 1;
    for(int i=1;i<=N;i++) F[i] = F[i-1]*i%mod, I[i] = pw(F[i], mod-2);
    if(a > b) swap(a,b);

    ll ans = 0, l = a-2, r = N-b;
    if(abs(a-b) == 1) {
        for(int i=0;i<r;i++) ans = (ans + ncr(l+i,i) * pw(2, r-i-1) % mod) % mod;
        for(int i=0;i<l;i++) ans = (ans + ncr(r+i,i) * pw(2, l-i-1) % mod) % mod;
    }
    ans += ncr(l+r,l) * 2 % mod * pw(2, abs(a-b)-2) % mod;
    ans %= mod;
    

    cout << ans;
    return 0;
}