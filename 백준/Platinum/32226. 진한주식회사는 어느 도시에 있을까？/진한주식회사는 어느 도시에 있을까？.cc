#include <bits/stdc++.h>
using namespace std;
using ll=long long;

double area(ll a, ll b, ll c) {
    double s=(a+b+c)/2.;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double n(ll a, ll b, ll c) {
    double s=area(a,b,c), h=s*2./c, ta=asin(h/a), tb=asin(h/b);
    return a*a*ta+b*b*tb - 2*s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b,c; cin >> a >> b >> c;
    if(a*a+b*b<=c*c) return cout << fixed << setprecision(12) << n(a,b,c), 0;
    cout << fixed << setprecision(12) << area(a,b,c)*4-(a*a+b*b+c*c)*0.5*M_PI + n(a,b,c) + n(b,c,a) + n(c,a,b);
    return 0;
}