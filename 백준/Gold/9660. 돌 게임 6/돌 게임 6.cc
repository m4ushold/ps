#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << (n%7==2 || n%7==0 ? "CY" : "SK");
    return 0;
}