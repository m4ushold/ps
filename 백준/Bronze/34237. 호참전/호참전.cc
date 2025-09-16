#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    for(int i=0;i<m;i++) {
        int g,x,y; cin >> g >> x >> y;
        int cnt=0;
        for(auto [a,b]:v) if(a+b<=g && a>=x && b>=y) cnt++;
        cout << cnt << '\n';
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}