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

struct S {
    ll l,r,sum,mx;
    S(ll a, ll b, ll c, ll d) {l=a,r=b,sum=c,mx=d;}
    S(ll x=0) : S(x, x, x, x) {}
};
S op(S a, S b) {
    return S(max(a.l, a.sum+b.l), max(b.r,a.r+b.sum),a.sum+b.sum,max({a.mx,b.mx,a.r+b.l}));
}
constexpr ll M = LLONG_MIN/2;
S e() {return S(M,M,0,M);}

void sol(int tc) {
    int n; cin >> n;
    segtree<S, op, e> seg(n);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        seg.set(i,S(x));
    }

    int q; cin >> q;
    for(int i=0,l,r;i<q;i++) {
        cin >> l >> r;
        cout << seg.qry(l-1,r-1).mx << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}