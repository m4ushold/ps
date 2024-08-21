#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll f(ll m, ll c, ll l, vector<ll> &v) {
    for(int i=v.size()-1;i>=0;i--) if(l-v[i] > m) {
        if(i==v.size()-1 || v[i+1]-v[i]>m) return -1;
        c--, l=v[i+1];
    }
    l=c>0?v[0]:l;
    if(c < 0 || l > m) return -1;
    return l;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll l,k,c; cin >> l >> k >> c;
    vector<ll> v(k);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    ll s=1,e=l,m;
    while(s<e) {
        m=(s+e)/2;
        if(f(m,c,l,v)<0) s=m+1;
        else e=m;
    }
    cout << e << ' ' << f(e,c,l,v) << '\n';

    return 0;
}