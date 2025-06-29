#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<18, mod = 1e9+7;

ll N, P, Q;

struct Seg {
    ll T[sz<<1], U[sz<<1], A[sz];
    void pa() {
        for(int i=1;i<=N;i++) cout << A[i] << ' '; cout << endl;
        for(int i=1;i<=N;i++) cout << A[N-i+1] << ' '; cout << endl;
    }
    void upd(int i, ll x) {
        T[i|sz] = (T[i|sz] + x * A[i] % mod) % mod;
        U[i|sz] = (U[i|sz] + x * A[N-i+1] % mod) % mod;
        i|=sz;
        while(i>>=1) T[i]=(T[i*2]+T[i*2+1])%mod, U[i]=(U[i*2]+U[i*2+1])%mod;
    }
    ll right(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=(ret+T[l++])%mod;
            if(~r&1) ret=(ret+T[r--])%mod;
        }
        return ret;
    }
    ll left(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=(ret+U[l++])%mod;
            if(~r&1) ret=(ret+U[r--])%mod;
        }
        return ret;
    }
} seg;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> N >> Q >> s;
    s = s.substr(2);
    P = stoll(s) * pw(pw(10, s.size()), mod-2) % mod;
    P = (1-P+mod) % mod;

    seg.A[0]=1;
    for(int i=1;i<=N;i++) seg.A[i] = seg.A[i-1] * P % mod;

    for(ll i=0,b,x;i<Q;i++) {
        char op; cin >> op;
        if(op == '+') cin >> b >> x, seg.upd(x, b);
        else if(op == '-') cin >> b >> x, seg.upd(x, mod-b);
        else {
            cin >> x;
            ll ans = seg.right(x,sz-1) * pw(pw(P, x),mod-2) % mod;
            ans += seg.left(1,x-1) * pw(pw(P, N-x+1), mod-2) % mod;
            ans%=mod;
            cout << ans << '\n';
        }
    }
    return 0;
}