#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct LazySeg {
    const static int sz=1<<18;
    ll T[sz<<1], L[sz<<1];
    ll& operator[](int i) {return T[sz|i];}
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=min(T[i*2],T[i*2+1]); }
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i]+=L[i];
        if(s!=e) L[i*2]+=L[i], L[i*2+1]+=L[i];
        L[i]=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=min(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 1e9;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return min(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} seg;

int A[202020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) seg[i]=i, cin >> A[i];
    seg.bld();

    for(int i=1;i<=n;i++) seg.upd(A[i],n,-1);
    cout << (seg.T[1]<0?"NIE\n":"TAK\n");

    int q; cin >> q;
    for(int i=0,a,b;i<q;i++) {
        cin >> a >> b;
        seg.upd(A[a],n,1), seg.upd(b,n,-1), A[a]=b;
        cout << (seg.T[1]<0?"NIE\n":"TAK\n");
    }

    return 0;
}