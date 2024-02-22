#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    int a,b,c;
    a=t/300, t%=300;
    b=t/60, t%=60;
    c=t/10, t%=10;
    if(t) cout << -1;
    else cout << a << ' ' << b << ' ' << c;
    return 0;
}