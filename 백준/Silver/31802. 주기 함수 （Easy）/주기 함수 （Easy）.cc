#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll p; cin >> p;
    vector<ll> v(p), s(p+1);
    for(ll &i:v) cin >> i;
    ll a,b; cin >> a >> b;
    for(ll i=1;i<=p;i++) s[i]+=s[i-1]+v[i-1];
    ll t=b-a;
    a=(a%p+p)%p, b=a+t;
    cout << b/p*s[p]+s[b%p] - a/p*s[p]-s[a%p];
    return 0;
}