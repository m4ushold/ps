#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i : v) cin >> i;
    reverse(v.begin(), v.end());

    ll ans = 0, mn = 1e9;
    for(ll i : v) mn = min(mn, i), ans += mn;
    cout << ans;
    return 0;
}