
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
    return os << p.first << ' ' << p.second;
}

template<typename T>
auto operator>>(istream &is, vector<T> &v) -> istream & {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
auto operator<<(ostream &os, const vector<T> v) -> ostream & {
    for (auto i: v) cout << i << ' ';
    return os;
}

template<typename T>
auto operator<<(ostream &os, const set<T> v) -> ostream & {
    for (auto i: v) cout << i << ' ';
    return os;
}

auto operator>>(istream &in, ll &x) -> istream & {
    string s;
    in >> s;

    x = 0;
    for (char i: s) x = x * 10 + i - '0';

    return in;
}

auto operator<<(ostream &os, ll x) -> ostream & {
    if (x == 0) return os << 0;

    string s;
    while (x) {
        s += static_cast<char>(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());

    return os << s;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int r = 0, w = 0;
        while (m--) {
            int x, y;
            cin >> x >> y;
            r = max(r, x);
            w = max(w, y);
        }

        if (r + w > n) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        cout << string(r, 'R') + string(n - r, 'W') << endl;
    }
}