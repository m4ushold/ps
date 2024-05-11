#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, a, s=0, c=0; cin >> n >> m;
    while(n--) cin >> a, s=max(0LL,a+s), c+=s>=m;
    cout << c;
    return 0;
}