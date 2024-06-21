#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll f(ll a) {
    if(a<10) return 0;
    ll r=1;
    while(a) r*=a%10, a/=10;
    return f(r)+1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << f(n);
    return 0;
}