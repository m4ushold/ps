#include <bits/stdc++.h>
using namespace std;
using ll=long long;

tuple<ll,ll,ll> ext_gcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    auto [g,x,y] = ext_gcd(b, a % b);
    return {g, y, x - a/b * y};
}

void sol(int tc) {
    ll a,b,c; cin >> a >> b >> c;
    auto [g,x,y] = ext_gcd(abs(a),abs(b));
    a/=g,b/=g,c/=g;
    tie(g,x,y) = ext_gcd(abs(a),abs(b));
    x*=c, y*=-c;
    
    a=abs(a), b=abs(b);
    // a>0 & b<0, make positive
    if(x<=0) {
        ll t=abs(x)/b+1;
        x+=t*b, y+=t*a;
    }
    if(y<=0) {
        ll t=abs(y)/a+1;
        x+=t*b, y+=t*a;
    }

    ll t = min(x/b,y/a);
    x-=t*b, y-=t*a;
    if(x==0 || y==0) x+=b, y+=a;
    cout << x << ' ' << y << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}