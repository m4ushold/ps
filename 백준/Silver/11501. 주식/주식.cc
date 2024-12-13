#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    int n; cin >> n;
    ll res=0, mx=-1;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    reverse(v.begin(),v.end());
    for(ll i:v) mx=max(mx, i), res+=mx-i;
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}