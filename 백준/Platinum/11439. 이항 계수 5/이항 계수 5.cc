#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<22;
vector<int> prime;
int N, K, MOD, sp[sz], cnt[sz];

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a;
        a=a*a%MOD, n/=2;
    }
    return res;
}

void Sieve(ll n) {
    for(int i=2; i<=n; i++){
        if(!sp[i]) prime.push_back(i);
        for(auto j : prime){
            if(i*j >= sz) break;
            sp[i*j] = j;
            if(i % j == 0) {
                break;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> MOD;
    Sieve(N);
    for(ll i:prime) for(ll j=i;j<=N;j*=i) cnt[i] += N/j - K/j - (N-K)/j;
    ll res=1;
    for(ll i:prime) res = res * pw(i,cnt[i]) % MOD;
    cout << res;
    return 0;
}