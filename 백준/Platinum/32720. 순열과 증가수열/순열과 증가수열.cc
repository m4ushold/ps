#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<20, mod=1e9+7;
ll F[sz]={1};

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,k; cin >> n >> k;
    for(int i=1;i<sz;i++) F[i]=F[i-1]*i%mod;
    ll res = F[n];
    for(ll i=1;i<=k;i++) {
        ll t = n/k;
        if(i <= n%k) t++;
        res = res * pw(F[t], mod-2) % mod;
    }
    cout << res;
    return 0;
}