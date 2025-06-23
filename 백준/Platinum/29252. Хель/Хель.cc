#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<19;

struct seg_t{
    ll T[sz << 1], U[sz<<1], S[sz<<1];

    seg_t() {
        for(int i=0;i<sz;i++) T[i]=1e12, U[i]=-1e12;
    }

    void upd(int i, ll x) {
        T[i|sz] = x;
        U[i|sz] = x;
        S[i|sz] = x;
        i|=sz;
        while (i >>= 1)
            T[i] = min(T[i * 2], T[i * 2 + 1]),
            U[i] = max(U[i*2], U[i*2+1]),
            S[i] = S[i*2]+S[i*2+1];
    }

    ll mn(int l, int r) {
        ll ret = 1e12;
        for (l |= sz, r |= sz; l <= r; l /= 2, r /= 2) {
            if (l & 1) ret = min(ret, T[l++]);
            if (~r & 1) ret = min(ret, T[r--]);
        }
        return ret;
    }
    ll mx(int l, int r) {
        ll ret=-1e12;
        for (l |= sz, r |= sz; l <= r; l /= 2, r /= 2) {
            if (l & 1) ret = max(ret, U[l++]);
            if (~r & 1) ret = max(ret, U[r--]);
        }
        return ret;
    }
    ll sum(int l, int r) {
        ll ret=0;
        for (l |= sz, r |= sz; l <= r; l /= 2, r /= 2) {
            if (l & 1) ret += S[l++];
            if (~r & 1) ret += S[r--];
        }
        return ret;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1,x;i<=n;i++) cin >> x, seg.upd(i, x);

    int m; cin >> m;
    for(int i=0,l,r,k;i<m;i++) {
        string s; cin >> s >> l >> r;
        if(s=="assign") seg.upd(l,r);
        else {
            cin >> k;
            if(k==0) cout << seg.sum(l,r)-seg.mn(l,r) << '\n';
            else if(k>0) cout << seg.sum(l,r)+seg.mx(l,r)*(k-1) << "\n";
            else cout << seg.sum(l,r)+seg.mn(l,r)*(k-1) << '\n';
        }
    }
    return 0;
}