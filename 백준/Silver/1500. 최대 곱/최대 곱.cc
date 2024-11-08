#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll s, k; cin >> s >> k;
    vector<ll> v(k, s/k);
    for(int i=0;i<s%k;i++) v[i]++;
    ll res=1;
    for(ll i:v) res*=i;
    cout << res;
    return 0;
}