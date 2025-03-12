#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17, mod=5'000'000;

struct fenwick {
    ll T[sz];
    ll sum(int i) {
        ll res=0;
        while(i) res = (res+T[i]) % mod, i -= i&-i;
        return res;
    }
    void add(int i, int x) {
        while(i<sz) T[i] += x, i += i&-i;
    }
} seg[55];

ll N, K, A[sz];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for(ll i=1;i<=N;i++) {
        cin >> A[i];
        seg[0].add(A[i], 1);
        for(ll k=1;k<K;k++) seg[k].add(A[i], seg[k-1].sum(A[i]-1));
    }
    cout << seg[K-1].sum(100'000);
    return 0;
}