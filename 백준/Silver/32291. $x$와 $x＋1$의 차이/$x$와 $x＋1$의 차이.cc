#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    n++;
    vector<ll> v;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            v.push_back(i);
            if(i!=n/i && i>1) v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    for(ll i:v) cout << i << ' ';
    return 0;
}