#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,t=9,a; cin >> n;
    while(t--) cin >> a, n-=a;
    cout << n;
    return 0;
}