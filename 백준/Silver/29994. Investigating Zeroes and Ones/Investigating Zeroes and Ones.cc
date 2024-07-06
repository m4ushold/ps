#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(),v.end()
using namespace std;

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
    }

    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
    }

    int odd = 0, even = 0;
    int res = 0;
    for (int i: sum) {
        if (i & 1) odd++, res += even;
        else even++, res += odd;
    }
    cout << res;
}