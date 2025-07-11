#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;

struct LazySeg {
    ll T[sz<<1], L[sz<<1];
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
        T[i]=max(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return max(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
    ll bs(int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(s == e) return s;
        int m=s+e>>1;
        prop(i*2, s, m), prop(i*2+1, m+1, e);
        if(T[i*2] == T[1])  return bs(i*2, s, m);
        else return bs(i*2+1, m+1, e);
    }
} seg;

pair<ll,ll> R[sz];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<sz;i++) R[i]={-1,-1};
    int n,m; cin >> n >> m;
    vector<array<ll,3>> v(n);
    for(auto &i:v) cin >> i[0] >> i[1] >> i[2];
    sort(v.begin(),v.end(),[](array<ll,3> a, array<ll,3> b) {
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });

    int prv=0;
    for(auto [x,y,w]:v) {
        seg.upd(x, x+w-1,1);
        int mx = seg.qry(0, sz-1);
        if(mx > prv) {
            prv = mx;
            R[mx] = {seg.bs(),y};
        }
    }
    for(int i=0,x;i<m;i++) {
        cin >> x;
        cout << R[x+1].first << ' ' << R[x+1].second << '\n';
    }
    return 0;
}