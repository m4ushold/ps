#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());
    ll sum=0;
    for(ll i=0;i<n;i++) {
        sum+=v[i];
        if(i*(i+1)/2 > sum) {
            return cout << -1, 0;
        }
    }
    if(sum != n*(n-1)/2) return cout << -1, 0;
    cout << 1;
    return 0;
}