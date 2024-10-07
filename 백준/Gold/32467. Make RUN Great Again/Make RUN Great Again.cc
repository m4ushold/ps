#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define int long long
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie();
    ll n, k, x;
    cin >> n >> k >> x;
    vector<P> A(n);
    for (auto &[a, b]: A)cin >> a >> b;
    auto jud = [&](ll j) {
        vector<ll> tmp;
        for (auto [a, b]: A) {
            ll now = b * (a - j);
            if (now > 0)tmp.push_back(now);
        }
        if (tmp.size() < x)return true;
        sort(all(tmp), greater<ll>());
        ll cost = 0;
        while (tmp.size() >= x) {
            cost += tmp.back();
            tmp.pop_back();
        }
        return cost < k;
    };

    ll l = -1, r = 1e9;
    while (l + 1 < r) {
        ll m = (l + r) >> 1;
        if (jud(m))r = m;
        else l = m;
    }
    cout << r << "\n";
}