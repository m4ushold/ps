#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(),v.end()
using namespace std;

auto digit_sum(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(1e6 + 1);
    while (n--) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 1e6; 0 <= i; i--) {
        if (not v[i]) continue;

        v[i - digit_sum(i)] += v[i];
    }

    for (int i = 1; i <= 1e6; i++) {
        v[i] += v[i - 1];
    }

    int x = v[1e6] - k;
    auto res = upper_bound(all(v), x) - v.begin();
    cout << digit_sum(res);
}