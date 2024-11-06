#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(), v.end()
using namespace std;

int calc(vector<int> v, vector<int> op) {
    int res = 0;
    for (int i = 0; i < op.size(); i++)
        if (op[i] == 0) { // combine
            v[i] = v[i] * 10 + v[i + 1];
            op.erase(op.begin() + i);
            v.erase(v.begin() + i + 1);
            i--;
        }

    for (int i = 0; i < op.size(); i++)
        if (op[i] == 1) { // mul
            v[i] = v[i] * v[i + 1];
            op.erase(op.begin() + i);
            v.erase(v.begin() + i + 1);
            i--;
        }

    res = v[0];
    for (int i = 1; i < v.size(); i++) { // add, sub
        if (op[i - 1] == 2) res += v[i];
        else if (op[i - 1] == 3) res -= v[i];
    }
    return res;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v(4), ans;
    for (int &i: v) cin >> i;
    sort(v.begin(), v.end());
    do {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (i + j + k == 0) continue;
                    ans.push_back(calc(v, {i, j, k}));
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.end() - lower_bound(ans.begin(), ans.end(), 0) << '\n';
}