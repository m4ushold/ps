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

int op(int a, int b) {return a+b;}
int e() {return 0;}

void sol(int tc) {
    int n; cin >> n;
    vector<pll> v;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        v.push_back({x,i});
    }
    
    sort(v.begin(),v.end());
    SegTree<int,op,e> seg(n);
    ll ans=0;
    for(auto [x,i]:v) {
        int l = seg.qry(0,i), r = seg.qry(i,n-1);
        ans += min(i-l, n-i-r-1);
        seg.upd(i,1);
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