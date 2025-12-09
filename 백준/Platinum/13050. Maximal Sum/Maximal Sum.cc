#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
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

const ll M = -1e15;

struct S {
    ll l,r,sum,mx;
    S(ll a, ll b, ll c, ll d) {l=a,r=b,sum=c,mx=d;}
    S(ll x=0) : S(x, x, x, x) {}
};

S e() {return S(M,M,0,M);}

S op(S a, S b) {
    return S(
        max(a.l, (a.sum < M/2 ? M : a.sum + b.l)),
        max(b.r, (b.sum < M/2 ? M : a.r + b.sum)),
        a.sum < M/2 || b.sum < M/2 ? M : a.sum + b.sum,
        max({a.mx, b.mx, (a.r < M/2 || b.l < M/2 ? M : a.r + b.l)})
    );
}

void sol(int tc) {
    int n,m; cin >> n >> m;
    segtree<S, op, e> seg(n);
    vector<ll> ans(m);
    vector<pll> a,b;

    for(int i=0,x;i<n;i++) cin >> x, a.push_back({x,i}), seg.set(i,S(M));
    for(int i=0,x;i<m;i++) cin >> x, b.push_back({x,i});
    sort(all(a)), sort(rall(b));
    for(auto [x,i]:b) {
        while(a.size() && a.back().first >= x) {
            auto [y,j] = a.back();
            seg.set(j,S(y));
            a.pop_back();
        }

        ans[i] = seg.qry(0,n-1).mx;
    }
    for(ll i:ans) {
        if(i == M) cout << 0 << ' ';
        else cout << i << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    sol(1);
    return 0;
}