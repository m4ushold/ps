#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    ll n, m; cin >> n >> m;
    ll res=0;
    if((n&1) && (m&1)) {
        res = (n/2-m/2)%m*2;
    } else if(n&1) {
        res = (n/2-m/2)%m*2+1;
    } else if(m&1) {
        res = (n/2-(m+1)/2)%m*2;
    } else {
        res = (n/2-m/2)%m*2;
    }
    if(res % m == 0) cout << 0;
    else cout << res;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}