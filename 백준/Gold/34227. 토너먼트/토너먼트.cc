#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
void sol(int tc) {
    ll a,b; cin >> a >> b;
    while(a<b) a=(a+1)>>1, b>>=1;
    int cnt=0;
    while(a>1) cnt+=a&1, a=(a+1)>>1;
    cout << cnt << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}