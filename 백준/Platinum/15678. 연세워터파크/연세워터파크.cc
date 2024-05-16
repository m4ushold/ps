#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<17;
    ll T[sz<<1];
    void build() { for(int i=sz-1;i>=1;i--) T[i]=max(T[i*2],T[i*2+1]); }
    void upd(int i, ll x) {
        i|=sz, T[i]=x;
        while(i>>=1) T[i]=max(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,d; cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> seg.T[seg.sz|i];
    seg.build();
    ll dap=seg.T[seg.sz|1];
    for(int i=2;i<=n;i++) {
        seg.upd(i,seg.T[seg.sz|i]+max(0LL,seg.qry(max(1,i-d),i-1)));
        dap=max(dap,seg.T[seg.sz|i]);
    }
    cout << dap;
    return 0;
}