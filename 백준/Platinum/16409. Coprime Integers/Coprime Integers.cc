#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 10'000'001;
vector<int> prime;
int sp[sz], mu[sz];

void Sieve(ll n=sz) {
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

void sol(int tc) {
    Sieve();
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll ans=0;
    for(int i=1;i<=min(b,d);i++) {
        ans += mu[i] * (b/i - (a-1)/i) * (d/i - (c-1)/i);
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