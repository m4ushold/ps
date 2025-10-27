#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct SegTree {
    int n, sz;
    vector<S> T;
    SegTree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void upd(int i, S x) {
        T[i|=sz] = x;
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

void sol(int tc) {
    int n; cin >> n;
    SegTree<ll,op,e> seg(n+1);
    vector<int> idx(n+1);
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        seg.upd(i,x);
        idx[x]=i;
    }

    ll ans=0, p=1;
    for(int i=1;i<=n;i++) {
        seg.upd(idx[i],0);
        int l = min<ll>(p,idx[i]), r = max<ll>(p,idx[i]);
        // cout << l << ' ' << r << " : " << seg.qry(l,r) << ' ' << seg.qry(1,l-1)+seg.qry(r,n) << ' ' << min(seg.qry(l,r), seg.qry(1,l-1)+seg.qry(r,n)) << endl;
        // for(int j=1;j<=n;j++) cout << seg.qry(j,j) << ' '; cout << endl;
        ans += min(seg.qry(l,r) + (p<=idx[i]?0:i), seg.qry(1,l-1)+seg.qry(r,n)+(p<idx[i] ? i : 0));
        p=idx[i];
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}