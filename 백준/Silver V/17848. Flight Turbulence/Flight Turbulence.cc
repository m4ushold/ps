#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int cnt=0;
    while(v[m]!=m) swap(m,v[m]), ++cnt;
    cout << cnt;
    return 0;
}