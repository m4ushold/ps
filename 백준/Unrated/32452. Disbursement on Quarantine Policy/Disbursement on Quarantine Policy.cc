#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
char A[111][111];
const ll mod = 1000000007;

ll pw(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, d0, d1, d2;
    cin >> n >> m >> d0 >> d1 >> d2;
    ll ans = 0;
    for (int s = 1; s <= n; s++) {
        for (int e = 1; e <= m; e++) {
            cin >> A[s][e];
        }
    }
    for (int s = 1; s <= n; s++) {
        for (int e = 1; e <= m; e++) {
            int a = A[s][e] == '?', b = 0, c = 0, d = 0, f = 0;
            if (A[s][e] == 'V') {
                ans = (ans + d0) % mod;
                continue;
            }
            for (auto [x, y]: {P(s + 1, e), P(s - 1, e), P(s, e - 1), P(s, e + 1)}) {
                if (x < 1 || x > n || y < 1 || y > m)continue;
                b += A[x][y] == '?';
                d += A[x][y] == 'V';
            }
            for (auto [x, y]: {P(s + 1, e + 1), P(s - 1, e - 1), P(s + 1, e - 1), P(s - 1, e + 1)}) {
                if (x < 1 || x > n || y < 1 || y > m)continue;
                c += A[x][y] == '?';
                f += A[x][y] == 'V';
            }
            ll a_ = pw(pw(2, a), mod - 2), b_ = pw(pw(2, b), mod - 2), c_ = pw(pw(2, c), mod - 2);
            ll aa = (pw(2, a) - 1) * a_ % mod, bb = (pw(2, b) - 1) * b_ % mod, cc = (pw(2, c) - 1) * c_ % mod;
            ll val = d0 * aa % mod, v2 = d1 * a_ % mod * bb % mod, v3 = a_ * b_ % mod * cc % mod * d2 % mod;
            if (d)v3 = 0, v2 = a_ * d1 % mod;
            else if (f)v3 = a_ * b_ % mod * d2 % mod;
            ans = (ans + val) % mod;
            ans = (ans + v2) % mod;
            ans = (ans + v3) % mod;
        }
    }
    cout << ans;
}