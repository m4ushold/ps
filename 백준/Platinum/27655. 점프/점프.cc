#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct LazySeg {
    const static int sz=1<<20;
    ll T[sz<<1], L[sz<<1];
    LazySeg() {
        for(int i=0;i<sz*2;i++) T[i]=1e9;
    }
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i]=L[i];
        if(s!=e) L[i*2]=L[i], L[i*2+1]=L[i];
        L[i]=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=v, prop(i,s,e); return;}
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
    int n,k; cin >> n >> k;
    if(n==1) return cout << 0, 0;
    vector<tuple<int,int,int>> v(n);
    vector<int> x;
    for(auto &[h,l,r]:v) cin >> l >> r >> h, x.push_back(l), x.push_back(r);
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()), x.end());
    for(auto &[h,l,r]:v) {
        l=lower_bound(x.begin(),x.end(),l)-x.begin();
        r=lower_bound(x.begin(),x.end(),r)-x.begin();
    }
    sort(v.begin(),v.end());

    int ans=1e9;
    for(auto [h,l,r]:v) {
        if(h==1) {
            seg.upd(l,r,1);
            continue;
        }
        
        int mn = seg.qry(l,r);
        seg.upd(l,r,mn+1);
        if(k==h) ans=min(ans, mn);
    }
    if(ans==1e9) cout << -1;
    else cout << ans;
    return 0;
}