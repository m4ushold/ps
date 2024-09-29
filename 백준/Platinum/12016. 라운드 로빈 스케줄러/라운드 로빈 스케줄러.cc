#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    static const ll sz=1<<17;
    ll T[sz<<1];
    void update(ll i, ll x) {
        T[i|=sz]=x;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    ll qry(ll l, ll r) {
        ll res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

ll A[101010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i=1,a;i<=n;i++) {
        cin >> a, v.emplace_back(a,i);
        seg.update(i,1);
    }

    sort(v.begin(),v.end());
    ll p=1, r=0;
    for(ll i=0;i<n;i++) {
        auto [a,b] = v[i];
        if(i) {
            A[b] = (v[i].first - v[i-1].first) * (n-i);
            if(v[i-1].second < b) A[b]+=seg.qry(v[i-1].second+1,b);
            else A[b]-=seg.qry(b+1, v[i-1].second);
        } else A[b] = (v[i].first-1)*n+seg.qry(1,b);
        seg.update(p=b, 0);
        r=A[b]+=r;
    }
    for(ll i=1;i<=n;i++) cout << A[i] << '\n';
    return 0;
}