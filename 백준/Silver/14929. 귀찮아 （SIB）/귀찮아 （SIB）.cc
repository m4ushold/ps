#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> v(n);
    ll s=0, r=0;
    for(ll &i:v) cin >> i, r+=i*s, s+=i;
    cout << r;
    return 0;
}