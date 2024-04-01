#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t,n,m; cin >> t;
    while (t--) cin >> n >> m, cout << 2*m-n << ' ' << m-(2*m-n) << '\n';
    return 0;
}