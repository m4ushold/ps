#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    double a,b,h; cin >> a >> b >> h;
    if(a==b) cout << -1;
    else {
        double s=(b-a)/hypot(h,b-a);
        if(a>b) swap(a,b);
        b/=s, a/=s;
        cout << fixed << setprecision(12) << b*b*M_PI-a*a*M_PI;
    }
    return 0;
}