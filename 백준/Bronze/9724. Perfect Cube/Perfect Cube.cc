#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<ll> v;
    for(ll i=1;i<=3000;i++) v.push_back(i*i*i);
    int t; cin >> t;
    for(int tc=1;tc<=t;tc++) {
        ll l,r; cin >> l >> r;
        cout << "Case #" << tc << ": ";
        cout << upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
        cout << '\n';
    }
    return 0;
}