#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 101010;
vector<int> prime;
int sp[sz], mu[sz];

void Sieve(ll n) {
    mu[1] = 1;
    for(int i=2; i<=n; i++){
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

int count(ll n) {
    ll res=0;
    for(ll i=2;i*i<=n;i++) {
        res+=-n/(i*i) * mu[i];
    }
    return n-res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Sieve(sz);
    int k; cin >> k;
    ll l=1, r=2e9;
    while(l<r) {
        int m=l+r>>1;
        if(count(m)>=k) r=m;
        else l=m+1;
    }
    cout << r;
    return 0;
}