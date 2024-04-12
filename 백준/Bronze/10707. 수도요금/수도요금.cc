#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,p; cin >> a >> b >> c >> d >> p;
    cout << min(a*p, b+max(0,p-c)*d);
    return 0;
}