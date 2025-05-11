#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<21;
struct LazySeg {
    ll mn[sz<<1], mx[sz<<1];
    void prop(int i, int op, ll v) {
        if(op == 1) mn[i]=max(mn[i],v), mx[i]=max(mx[i],v);
        else mn[i]=min(mn[i],v), mx[i]=min(mx[i],v);
    }
    void upd(int l, int r, int op, ll v, int i=1, int s=0, int e=sz-1) {
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {prop(i,op,v);return;}
        int m=s+e>>1;
        for(int c:{i<<1, i<<1|1}) prop(c,1,mn[i]), prop(c,2,mx[i]);
        mn[i]=0, mx[i]=1e9;
        upd(l,r,op,v,i*2,s,m), upd(l,r,op,v,i*2+1,m+1,e);
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for(int i=0,op,l,r,h;i<k;i++) {
        cin >> op >> l >> r >> h;
        seg.upd(l,r,op,h);
    }
    for(int i=0;i<n;i++) {
        seg.upd(i,i,1,0);
        cout << seg.mn[sz|i] << '\n';
    }
    return 0;
}