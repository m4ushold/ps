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

auto match(size_t cur, vector<vector<size_t>> &edges, vector<size_t> &b1, vector<size_t> &b2,
           vector<bool> &visited) -> size_t {
    visited[cur] = true;

    for (auto &next: edges[cur]) {
        size_t prev = b2[next];
        if (not prev or (not visited[prev] and match(prev, edges, b1, b2, visited))) {
            b1[cur] = next;
            b2[next] = cur;
            return 1;
        }
    }
    return 0;
}


auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> v(n);
    cin >> v;

    vector edges(n + 1, vector<size_t>());
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            string a = v[i];
            string b = v[j];

            int cnt = 0;
            for (size_t k = 0; k < a.size(); k++) {
                if (a[k] != b[k]) cnt++;
            }

            if (cnt == 2) {
                edges[i + 1].push_back(j + 1);
            }
        }
    }

    vector<size_t> b1(n + 1);
    vector<size_t> b2(n + 1);

    vector<bool> visited(n + 1, false);
    size_t res = 0;
    for (size_t i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        res += match(i, edges, b1, b2, visited);
    }
    cout << n - res / 2 << endl;
}