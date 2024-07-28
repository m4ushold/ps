#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin >> n >> m;
    vector<ll> v;
    for(int i=0;i<n;i++) {
        ll s=0;
        for(ll j=0,a;j<m;j++) cin >> a, s+=a;
        v.push_back(s);
    }
    ll t=reduce(v.begin(),v.end(),0LL,bit_xor<ll>());
    cout << (t ? "august14" : "ainta");
    return 0;
}