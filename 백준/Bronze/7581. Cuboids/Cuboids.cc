#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b,c,d;
    while(cin >> a >> b >> c >> d && (a || b)) {
        if(a*b*c) cout << a << ' ' << b << ' ' << c << " " << a*b*c << '\n';
        else if(!a) cout << d/b/c << ' ' << b << ' ' << c << ' ' << d << "\n";
        else if(!b) cout << a << ' ' << d/a/c << ' ' << c << ' ' << d << '\n';
        else cout << a << ' ' << b << ' ' << d/a/b << ' ' << d << '\n';
    }
    return 0;
}