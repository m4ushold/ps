#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll c, k, p, a=0; cin >> c >> k >> p;
    for(int i=0;i<=c;i++) a+=k*i+p*i*i;
    cout << a;
    return 0;
}