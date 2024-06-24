#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int a=n/2, b=n+1>>1;
    if(a!=b) cout << "Either";
    else if(a&1) cout << "Odd";
    else cout << "Even";
    return 0;
}