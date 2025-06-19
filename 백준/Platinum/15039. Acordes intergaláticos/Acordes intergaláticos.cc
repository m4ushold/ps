#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<17;
struct LazySeg {
    array<int,9> T[sz<<1];
    int L[sz<<1];
    void init() {
        for(int i=0;i<sz*2;i++) for(int j=0;j<9;j++) T[i][j]=0;
        for(int i=0;i<sz;i++) T[sz|i][1]=1;
        for(int i=sz-1;i;i--) {
            T[i][1]=T[i*2][1]+T[i*2+1][1];
        }
    }
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        array<int,9> tmp;
        for(int j=0;j<9;j++) tmp[j] = T[i][(j-L[i]+9)%9];
        T[i] = tmp;
        if(s!=e) L[i*2]=(L[i*2]+L[i])%9, L[i*2+1]=(L[i*2+1]+L[i])%9;
        L[i]=0;
    }
    void upd(int l, int r, int v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        for(int j=0;j<9;j++) T[i][j]=T[i*2][j]+T[i*2+1][j];
    }
    array<int,9> qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return array<int,9>();
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        array<int,9> res;
        auto a=qry(l,r,i*2,s,m), b=qry(l,r,i*2+1,m+1,e);
        for(int j=0;j<9;j++) res[j]=a[j]+b[j];
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    seg.init();
    int n,q; cin >> n >> q;
    for(int i=0,a,b;i<q;i++) {
        cin >> a >> b;
        auto res = seg.qry(a,b);
        int mx=-1, f=0;
        for(int i=8;i>=0;i--) {
            if(mx < res[i]) mx=res[i], f=i;
        }
        seg.upd(a,b,f);
    }
    for(int i=0;i<n;i++) {
        seg.qry(i,i);
        for(int j=0;j<9;j++) if(seg.T[sz|i][j]) cout << j << '\n'; 
    }

    return 0;
}