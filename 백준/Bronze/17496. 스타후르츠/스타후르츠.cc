#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,t,c,p; cin >> n >> t >> c >> p;
    cout << max(n/t-(n%t==0),0)*c*p;
    return 0;
}