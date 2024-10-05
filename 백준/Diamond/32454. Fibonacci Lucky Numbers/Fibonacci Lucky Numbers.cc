#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll __int128_t
constexpr int mod = 1e10;
using matrix = vector<vector<ll> >;

matrix operator*(const matrix &m1, const matrix &m2) {
    matrix res(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] += m1[i][k] * m2[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

auto modpow(matrix m, int n) {
    matrix res = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) res = res * m;
        m = m * m;
        n >>= 1;
    }
    return res;
}

auto fisano_modpow(ll base, int exp, int pmod) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % pmod;
        base = base * base % pmod;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const matrix I = {{1, 1}, {1, 0}};

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll cur = 7;
        cur = fisano_modpow(cur, n, 16e8);
        cur = fisano_modpow(7, cur, 4e9);
        cur = fisano_modpow(7, cur, 15e9);

        matrix m = modpow(I, cur);
        cout << setfill('0') << setw(10);
        cout << static_cast<long long>(m[1][0]) << endl;
    }
}