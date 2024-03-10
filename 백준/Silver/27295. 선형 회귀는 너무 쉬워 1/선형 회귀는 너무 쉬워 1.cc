#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,b; cin >> n >> b;
    vector<pair<ll,ll>> v(n);
    ll x=0,y=0;
    for(auto &[i,j]:v) cin >> i >> j, i=-i, j=b-j, x+=i, y+=j;

    int f=x/(x?abs(x):1)*y/(y?abs(y):1)<0;
    x=abs(x), y=abs(y);
    ll g=gcd(x,y);
    if(g) x/=g, y/=g;

    if(!x) {
        cout << "EZPZ\n";
        return 0;
    }

    if(f) cout << "-";

    if(x==1) cout << y;
    else cout << y << '/' << x;
    return 0;
}