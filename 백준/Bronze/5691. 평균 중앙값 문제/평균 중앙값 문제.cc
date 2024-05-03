#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b;
    while(cin >> a >> b && a) cout << min(a,b)-abs(a-b) << '\n';
    return 0;
}