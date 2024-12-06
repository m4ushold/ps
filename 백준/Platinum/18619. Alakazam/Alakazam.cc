#include <bits/stdc++.h>
using namespace std;
using lf=long double;

struct LazySeg {
    const static int sz=1<<18;
    lf T[sz<<1], L[sz<<1];
    void prop(int i, int s, int e) {
        if(abs(L[i]) < 1e-7) return;
        T[i]=L[i]*(e-s+1);
        if(s!=e) L[i*2]=L[i], L[i*2+1]=L[i];
        L[i]=0;
    }
    void upd(int l, int r, lf v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=(T[i*2]+T[i*2+1]);
    }
    lf qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return (qry(l,r,i*2,s,m)+qry(l,r,i*2+1,m+1,e));
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=1,a;i<=n;i++) cin >> a, seg.upd(i, i, a);
    for(int i=0,l,r,j;i<m;i++) {
        string op; cin >> op;
        if(op == "get") cin >> j, cout << fixed << setprecision(20) << seg.qry(j,j) << '\n';
        else {
            cin >> l >> r;
            lf a = seg.qry(l,r)/(r-l+1);
            seg.upd(l,r,a);
        }
    }
    return 0;
}