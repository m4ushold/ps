#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool f(ll x) {
    for(ll i=0,s=sqrt(x)-1;i<3;i++,s++) if(s*s==x) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> v(n), a;
    for(ll &i:v) cin >> i;
    a=v;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        ll g=gcd(a[i],v[i]);
        a[i]/=g, v[i]/=g;
        if(!f(a[i]) || !f(v[i])) {cout << "NO"; return 0;}
    }
    cout << "YES";
    return 0;
}