#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    if(n<=4) {cout << 4; return 0;}
    ll a=sqrt(n)-1, b=a;
    while((a+1)*(b+1) < n) a < b ? a++ : b++;
    cout << 2*a+2*b;
    return 0;
}