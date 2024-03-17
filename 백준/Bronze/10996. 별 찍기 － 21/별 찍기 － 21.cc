#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=2*n;i++) {
        for(int j=1;j<=n;j++) cout << ((i+j)&1 ? ' ' : '*');
        cout << '\n';
    }
    return 0;
}