#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n; cin >> n;
    map<ll,ll> m;
    for(ll i=0,a;i<n;i++) cin >> a, m[a]++;
    for(auto [i,j]:m) if(j>n/2) {cout << i << "\n"; return;}
    cout << "SYJKGW\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}