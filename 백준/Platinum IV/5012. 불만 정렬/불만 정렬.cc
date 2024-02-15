#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll T[1<<18], sz=1<<17;
    void init() { for(int i=0;i<sz*2;i++) T[i]=0; }
    void update(int v, int x) {
        v|=sz, T[v]+=x;
        while(v>>=1) T[v]=T[v*2]+T[v*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz, r|=sz;l<=r;l/=2, r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> v(n);
    vector<pair<ll,ll>> lr(n);
    for(ll &i:v) cin >> i;
    for(int i=0;i<n;i++) seg.update(v[i],1), lr[i].first=seg.query(v[i]+1,n);
    seg.init();
    for(int i=n-1;i>=0;i--) seg.update(v[i],1), lr[i].second=seg.query(1,v[i]-1);

    ll res=0;
    for(auto [l,r]:lr) res+=l*r;
    cout << res;
    return 0;
}