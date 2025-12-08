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
    ll lmn, rmn, lmx, rmx, mn, mx, sum;
    S(ll lmn, ll rmn, ll mn, ll lmx, ll rmx, ll mx, ll sum) : lmn(lmn), rmn(rmn), mn(mn), lmx(lmx), rmx(rmx), mx(mx), sum(sum) {}
    S(ll x) {lmn=rmn=mn=lmx=rmx=mx=sum=x;}
};

pll fn(pll a, pll b) {
    if(a.first == b.first) return a.second < b.second ? a : b;
    return a.first > b.first ? a : b;
}

S op(S a, S b) {
    return S(min(a.lmn, a.sum+b.lmn), min(b.rmn,b.sum+a.rmn), min({a.mn,b.mn,a.rmn+b.lmn}), max(a.lmx,a.sum+b.lmx), max(b.rmx,b.sum+a.rmx), max({a.mx,b.mx,a.rmx+b.lmx}), a.sum+b.sum);
}
constexpr ll MN = LLONG_MIN/4, MX = LLONG_MAX/4;
S e() {return S(MX, MX, MX, MN, MN, MN, 0);}

void sol(int tc) {
    int n,q; cin >> n >> q;
    vector<ll> v(n);
    segtree<S, op, e> seg(n);
    for(int i=0;i<n;i++) seg.set(i,S(0));
    for(int i=0,op,a,b;i<q;i++) {
        cin >> op;
        if(op==1) {
            cin >> a >> b, a--, v[a]+=b;
            seg.set(a,S(v[a]));
        } else {
            S res = seg.qry(0,n-1);
            ll ans = res.mx;
            if(res.sum != res.mn) ans = max(ans, res.sum - res.mn);
            cout << ans << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}