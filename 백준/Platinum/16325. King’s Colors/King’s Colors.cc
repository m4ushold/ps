#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;
ll N, K, F[3030], I[3030];

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod,n/=2;
    }
    return res;
}

ll ncr(ll n, ll r) {
    return F[n]*I[r]%mod*I[n-r]%mod;
}

void sol(int tc) {
    cin >> N >> K;
    F[0]=1, I[0]=1;
    for(int i=1;i<=N;i++) F[i]=F[i-1]*i%mod, I[i]=pw(F[i],mod-2);

    ll ans=0;
    for(int i=0;i<=K-2;i++) {
        ll tmp=i&1?-1:1;
        tmp = ncr(K,i) * (K-i) % mod * pw(K-i-1,N-1) % mod * tmp % mod;
        ans = (ans+tmp+mod)%mod;
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