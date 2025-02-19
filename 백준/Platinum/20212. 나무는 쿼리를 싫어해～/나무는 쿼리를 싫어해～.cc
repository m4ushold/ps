#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());

using namespace std;
using ll = long long;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

// rope
#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension


struct LazySeg {
    const static int sz=1<<18;
    ll T[sz<<1], L[sz<<1], D[sz];
    ll& operator[](int i) {return T[sz|i];}
    void bld(vector<ll> &v) {
        for(int i=0;i<v.size();i++) D[i]=v[i];
        // for(int i=sz-1;i>=1;i--) T[i]=(T[i*2]+T[i*2+1]); 
    }
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i]+=(D[e]-D[s-1])*L[i];
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

vector<array<ll,3>> Q[101010], A;

void sol(int tc) {
    ll n; cin >> n;
    vector<ll> v;
    vector<array<ll,4>> qry(n);
    for(auto &[a,b,c,d]:qry) {
        cin >> a >> b >> c >> d;
        v.push_back(b), v.push_back(c);
        v.push_back(b-1), v.push_back(c-1);
    }
    v.push_back(0);
    compress(v);

    ll idx=0;
    for(auto &[a,b,c,d]:qry) {
        b = lower_bound(all(v), b) - v.begin();
        c = lower_bound(all(v), c) - v.begin();

        if(a == 1) A.push_back({b,c,d});
        else Q[d].push_back({idx++,b,c});
    }

    seg.bld(v);

    vector<ll> ans(n-A.size());
    ll kth=1;
    for(auto [i,j,k]:A) {
        seg.upd(i,j,k);
        for(auto [r,ii,jj]:Q[kth]) ans[r]=seg.qry(ii,jj);
        kth++;
    }
    for(ll i:ans) cout << i << '\n';
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}