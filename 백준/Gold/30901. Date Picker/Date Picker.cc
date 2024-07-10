#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(), v.end()

using namespace std;

auto operator>>(istream &is, pair<int, int> &p) -> istream & {
    return is >> p.first >> p.second;
}

auto operator<<(ostream &os, const pair<int, int> &p) -> ostream & {
    return os << p.first << p.second;
}

template<typename T>
auto operator<<(ostream &os, const vector<T> v) -> ostream & {
    for (auto i: v) cout << i << ' ';
    return os;
}


auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> week(7);
    for (auto &i: week) cin >> i;

    int d, h;
    cin >> d >> h;

    vector<bool> days(7);
    fill(days.end() - d, days.end(), true);

    int MAX = 0;
    do {
        vector<int> hours(24);
        for (int i = 0; i < 7; i++) {
            if (not days[i]) continue;
            for (int j = 0; j < 24; j++) {
                hours[j] += week[i][j] == '.';
            }
        }
        sort(all(hours));

        int cur = accumulate(hours.end() - h, hours.end(), 0LL);
        MAX = max(MAX, cur);
    } while (next_permutation(all(days)));

    cout << fixed << setprecision(6) << MAX / static_cast<double>(d * h);
}