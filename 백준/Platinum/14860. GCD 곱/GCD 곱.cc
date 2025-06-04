#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll N, M;

ll pw(ll a, ll n) {
    ll res = 1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> primes, S;
    cin >> N >> M;
    if(N>M) swap(N,M);
    S.resize(N+1);
    S[0]=S[1]=1;
    for(int i=2;i<=N;i++) if(!S[i]) {
        for(int j=2*i;j<=N;j+=i) S[j]=1;
        primes.push_back(i);
    }
    ll ans = 1;
    for(int i:primes) {
        ll p = i;
        while(p <= min(N, M)) ans = ans * pw(i,(N/p) * (M/p)) % MOD, p*=i;
    }
    cout << ans;
    return 0;
}