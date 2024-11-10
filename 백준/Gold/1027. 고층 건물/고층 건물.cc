#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll ccw(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c) {
    ll res=a.first*b.second+b.first*c.second+c.first*a.second;
    res-=b.first*a.second+c.first*b.second+a.first*c.second;
    return (res>0)-(res<0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> v(n), c(n);
    for(ll &i:v) cin >> i;
    for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) {
        ll f=1;
        for(ll k=i+1;k<j;k++) {
            if(ccw({i,v[i]},{k,v[k]},{j,v[j]})<=0) {f=0;break;}
        }
        if(f) c[i]++, c[j]++;
    }
    cout << *max_element(c.begin(),c.end());
    return 0;
}