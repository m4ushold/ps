#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mod=1e9+7;
ll F[1<<20]={1};

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

ll ncr(ll n, ll r) {
    return F[n]*pw(F[r],mod-2)%mod*pw(F[n-r],mod-2)%mod;
}

ll f(ll s, ll a, ll b, ll c) {
    return ncr(s,a)*ncr(s,b)%mod*ncr(s,c)%mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<1<<20;i++) F[i]=F[i-1]*i%mod;
    ll s,a,b,c; cin >> s >> a >> b >> c;
    ll ans = f(s,a,b,c);
    for(int i=1,j=-1;i<=s-max({a,b,c});i++,j*=-1) {
        ans += ncr(s,i) * f(s-i,a,b,c)%mod * j;
        ans = (ans + mod) % mod;
    }
    cout << ans;
    return 0;
}