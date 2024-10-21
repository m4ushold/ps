#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Seg {
    static const int sz = 1 << 19;
    vector<ll> T[sz << 1];

    void build() {
        for (int i = sz - 1; i >= 1; i--) {
            T[i].resize(T[i * 2].size() + T[i * 2 + 1].size());
            merge(T[i * 2].begin(), T[i * 2].end(), T[i * 2 + 1].begin(), T[i * 2 + 1].end(), T[i].begin());
        }
    }

    ll diff(int i, ll x) {
        auto it1 = lower_bound(T[i].begin(), T[i].end(), x);
        ll diff1 = it1 != T[i].end() ? abs(*it1 - x) : LLONG_MAX;

        auto it2 = it1 != T[i].begin() ? prev(it1) : it1;
        ll diff2 = it1 != T[i].begin() ? abs(*it2 - x) : LLONG_MAX;

        return min(diff1, diff2);
    }
    
    ll query(int l, int r, ll x) {
        ll res = LLONG_MAX;
        for (l |= sz, r |= sz; l <= r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, diff(l++, x));
            if (~r & 1) res = min(res, diff(r--, x));
        }
        return res;
    }
} seg;

ll N, Q, A[303030];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i - 1];
        seg.T[seg.sz | i].push_back(2 * A[i]);
    }
    seg.build();
    
    cin >> Q;
    for (int i = 0, l, r; i < Q; i++) {
        cin >> l >> r;
        int len = (r - l + 1) / 3 + 1;
        if ((r - l + 1) % 3 == 0) len--;

        int ll = l + len - 1;
        int rr = r - len;
        cout << seg.query(ll, rr, A[r] + A[l - 1]) << '\n';
    }
    return 0;
}
