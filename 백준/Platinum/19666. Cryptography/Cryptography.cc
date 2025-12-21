#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, sz;
    vector<S> T;
    segtree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void set(int i, S x) {
        T[i|=sz] = x;
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    void add(int i, S x) {
        T[i|sz] = op(T[i|=sz], x);
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    S qry(int l, int r) {
        S L=e(), R=e();
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) L=op(L,T[l++]);
            if(~r&1) R=op(T[r--],R);
        }
        return op(L,R);
    }
};

int op(int a, int b) {return a+b;}
int e() {return 0;}

constexpr int mod = 1e9+7;
void sol(int tc) {
    int n; cin >> n;
    vector<ll> fac(n+1,1);
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;

    vector<int> v(n), a;
    segtree<int,op,e> seg(n);
    for(int &i:v) cin >> i;
    a = v, prs(a);
    for(int &i:v) i = lower_bound(all(a), i)-a.begin(), seg.set(i,1);

    ll ans=1;
    for(int i=0;i<n;i++) {
        ans = (ans + (seg.qry(0,v[i])-1) * fac[n-i-1]) % mod;
        seg.set(v[i],0);
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}