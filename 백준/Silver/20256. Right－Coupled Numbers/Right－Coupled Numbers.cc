#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(), v.end()
using namespace std;

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        bool flag = false;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (x / i <= 2 * i)flag = true;
            }
        }
        cout << flag << endl;
    }
}