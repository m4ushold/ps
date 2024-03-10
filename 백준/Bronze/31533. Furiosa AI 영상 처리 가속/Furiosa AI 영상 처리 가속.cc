#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    double a,n,m; cin >> a >> n >> m;
    n/=a, m/=a;
    cout << fixed << setprecision(12) << min({max(n,m*a), max(n*a,m), 2*n, 2*m});
    
    return 0;
}