#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    if(n+m-1<=k) {
        cout << "YES\n";
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) cout << i+j-1 << ' ';
            cout << '\n';
        }
    } else cout << "NO\n";
    return 0;
}