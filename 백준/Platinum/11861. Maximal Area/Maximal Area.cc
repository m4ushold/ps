#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    int sz=1<<20;
    tuple<ll,ll,ll> T[1<<21];
    tuple<ll,ll,ll> f(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) { 
        auto [mna,ia,aa]=a;
        auto [mnb,ib,bb]=b;
        if(mna<mnb) return {mna,ia,aa+bb};
        else return {mnb,ib,aa+bb};
    }
    void init() { for(int i=0;i<sz*2;i++) T[i]={1e9,0,0}; }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=f(T[i*2],T[i*2+1]); }
    void update(int v, int x) {
        T[v|sz]={x,v,x}, v|=sz;
        while(v>>=1) T[v]=f(T[v*2],T[v*2+1]);
    }
    tuple<ll,ll,ll> query(int l, int r) {
        tuple<ll,ll,ll> res={1e9,0,0};
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=f(res,T[l++]);
            if(~r&1) res=f(res,T[r--]);
        }
        return res;
    }
} seg;

ll f(int l, int r) {
    auto [mn,i,s]=seg.query(l,r);
    if(l>=r) return s;
    return max({mn*(r-l+1),f(l,i-1),f(i+1,r)});
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    seg.init();
    for(int i=1,a;i<=n;i++) cin >> a, seg.T[seg.sz|i]={a,i,a};
    seg.build();
    cout << f(1,n);
    return 0;
}