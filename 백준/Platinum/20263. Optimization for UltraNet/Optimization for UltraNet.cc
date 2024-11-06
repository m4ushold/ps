#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
const int N = 10'101;
vector<P> tG[N], G[N];

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edge, e2;
    for (int s = 0; s < m; s++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
        tG[u].emplace_back(v, w);
        tG[v].emplace_back(u, w);
    }
    int low = 1e9;
    for (int s = 1; s <= n; s++) {
        int mx = 0;
        for (auto [v, w]: tG[s])mx = max(mx, w);
        low = min(low, mx);
    }
    sort(all(edge));
    vector<int> S(n + 1, -1);
    function<int(int)> find = [&](int a) { return S[a] < 0 ? a : S[a] = find(S[a]); };
    auto Union = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)return 0;
        if (S[a] > S[b])swap(a, b);
        S[a] += S[b];
        S[b] = a;
        return 1;
    };
    auto jud = [&](int i, int op) {
        S = vector<int>(n + 1, -1);
        for (int s = i; s < m; s++) {
            auto [w, u, v] = edge[s];
            if (Union(u, v)) {
                if (op)e2.push_back({-w, u, v});
            }
            if (-S[find(u)] == n)break;
        }
        return -S[find(1)] == n;
    };
    int l = 0, r = m;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (jud(m, 0))l = m;
        else r = m;
    }
    int i = l;
    jud(i, 1);
    int ans = 0;
    S = vector<int>(n + 1, -1);
    sort(all(e2));
    for (auto [w, u, v]: e2) {
        int l_ = -S[find(u)], r_ = -S[find(v)];
        if (Union(u, v))ans += -w * l_ * r_;
    }
    cout << ans;
}