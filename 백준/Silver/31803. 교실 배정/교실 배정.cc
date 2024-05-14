#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,r=1; cin >> n;
    if(n&1) r=n, n--;
    for(ll i=n-1;i>1;i-=2) r*=i;
    cout << r;
    return 0;
}