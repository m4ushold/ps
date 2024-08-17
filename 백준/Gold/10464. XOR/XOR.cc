#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
void solve() {
    int s,f; cin >> s >> f;
    int res=0, i;
    for(i=s;i<=f && i%4;i++) res^=i;
    for(int j=f;j>i && j%4!=3 ;j--) res^=j;
    cout << res << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}