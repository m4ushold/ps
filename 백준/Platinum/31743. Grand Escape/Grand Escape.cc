#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct LazySeg {
    const static int sz=1<<17;
    ll T[sz<<1], L[sz<<1];
    ll& operator[](int i) {return T[sz|i];}
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=(T[i*2]+T[i*2+1]); }
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i]+=(e-s+1)*L[i];
        if(s!=e) L[i*2]+=L[i], L[i*2+1]+=L[i];
        L[i]=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=(T[i*2]+T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return (qry(l,r,i*2,s,m)+qry(l,r,i*2+1,m+1,e));
    }
} seg;

ll R[1<<18];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n;
    vector<array<int,4>> v;
    for(int i=0,l,r,y;i<n;i++) {
        cin >> l >> r >> y;
        v.push_back({y,1,l,r});
    }
    cin >> m;
    for(int i=0,x,y;i<m;i++) {
        cin >> x >> y;
        v.push_back({y,2,x,i});
    }
    sort(v.begin(),v.end());

    for(auto [a,b,c,d]:v) {
        if(b == 1) seg.upd(c,d,a);
        else R[d] = seg.qry(c,c) + a;
    }
    for(int i=0;i<m;i++) cout << R[i] << '\n';
    return 0;
}