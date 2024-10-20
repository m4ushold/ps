#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1010101;
vector<ll> prime;
ll sp[sz], mu[sz];

void Sieve(ll n) {
    mu[1] = 1;
    for(ll i=2; i<=n; i++){
        if(!sp[i]){
            prime.push_back(i);
            mu[i] = -1;
        }
        for(auto j : prime){
            if(i*j >= sz) break;
            sp[i*j] = j;
            if(i % j == 0) {
                mu[i*j] = 0;
                break;
            }
            mu[i*j] = mu[i] * mu[j];
        }
    }
}

ll count(ll n) {
    ll res=0;
    for(ll i=2;i*i<=n;i++) {
        res+=-n/(i*i) * mu[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Sieve(sz);
    ll k; cin >> k;
    ll l=1, r=1e12;
    while(l<r) {
        ll m=l+r>>1;
        if(count(m)>=k) r=m;
        else l=m+1;
    }
    cout << r;
    return 0;
}