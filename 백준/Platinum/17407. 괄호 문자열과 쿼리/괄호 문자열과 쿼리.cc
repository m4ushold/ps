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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int sum=0, q; cin >> q;
    for(int i=0;i<s.size();i++) sum+=seg[i]=s[i]=='('?1:-1, seg[i]+=seg[i-1];
    seg.bld();

    int cnt=0;
    for(int i=0,j;i<q;i++) {
        cin >> j, j--;
        if(s[j] == '(') {
            s[j] = ')', sum-=2;
            seg.upd(j,s.size()-1,-2);
        } else {
            s[j] = '(', sum+=2;
            seg.upd(j,s.size()-1, 2);
        }
        if(sum==0 && seg.T[1]==0) cnt++;
    }
    cout << cnt;

    return 0;
}