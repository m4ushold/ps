#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<22;
    ll T[sz<<1];
    void init() { for(int i=0;i<sz*2;i++) T[i]=1e9; }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=min(T[i*2],T[i*2+1]); }
    void update(int v, int x) {
        v|=sz, T[v]=x;
        while(v>>=1) T[v]=min(T[v*2],T[v*2+1]);
    }
    ll query(int l, int r) {
        ll res=1e9;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=min(res,T[l++]);
            if(~r&1) res=min(res,T[r--]);
        }
        return res;
    }
} seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    seg.init();
    for(int i=1,a;i<=m;i++) cin >> a, seg.T[seg.sz|a]=a;
    seg.build();
    
    for(int i=1,a;i<=k;i++) {
        cin >> a;
        a=seg.query(a+1,n);
        cout << a << '\n';
        seg.update(a,1e9);
    }
    return 0;
}