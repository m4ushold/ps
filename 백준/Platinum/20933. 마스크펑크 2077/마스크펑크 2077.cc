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

ll op(ll a, ll b) {return a+b;}
ll e() {return 0;}

ll op1(ll a, ll b) {return min(a,b);}
ll e1() {return LLONG_MAX;}

int lt(segtree<ll,op,e> &seg, int x, int t) {
    int l=0,r=x-1;
    while(l<r) {
        int m=l+r+1>>1;
        if(seg.qry(m,x-1) > t) l=m;
        else r=m-1;
    }
    return l+1;
}

int rt(segtree<ll,op,e> &seg, int x, int t) {
    int l=x,r=seg.n-1;
    while(l<r) {
        int m=l+r>>1;
        if(seg.qry(x,m) > t) r=m;
        else l=m+1;
    }
    return r;
}

void sol(int tc) {
    int n; cin >> n;
    segtree<ll,op,e> dst(n+1);
    segtree<ll,op1,e1> cost(n+1);
    for(int i=1,x;i<=n;i++) cin >> x, cost.set(i,x);
    for(int i=1,x;i<n;i++) cin >> x, dst.set(i,x);

    int q; cin >> q;
    for(int i=0,x,t;i<q;i++) {
        string s; cin >> s >> x >> t;
        if(s == "CALL") {
            int l = lt(dst,x,t), r = rt(dst,x,t);
            cout << cost.qry(l,r) << endl;
        } else dst.set(x,t);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}