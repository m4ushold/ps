#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

//#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(),v.end()
using namespace std;

// n: 집합 1의 크기
// m: 집합 2의 크기

// 매칭 함수
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

    vector<bool> is_prime(2e7, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < 2e7; i++) {
        if (not is_prime[i]) {
            continue;
        }

        for (int j = i * i; j < 2e7; j += i) {
            is_prime[j] = false;
        }
    }

    int n;
    cin >> n;

    vector<int> v(n);
    for (int &i: v) cin >> i;

    sort(all(v));
    reverse(all(v));
    while (v.size() > 1 and v[v.size() - 2] == 1) {
        v.pop_back();
    }
    n = v.size();

    vector edges(n + 1, vector<size_t>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (is_prime[v[i] + v[j]]) {
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
    cout << n - (res + 1) / 2;
}