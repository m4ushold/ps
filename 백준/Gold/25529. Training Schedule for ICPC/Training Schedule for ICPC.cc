#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n, m; cin >> n >> m;
    if(!n && !m)exit(0);
    if(!n){
        cout << -m * m << "\n";
        return;
    }
    ll ans = LLONG_MIN;
    for(ll s=1; s<=n; s++){
        if(s-1 > m)continue;
        ll L = n - (s-1);
        L = L * L + s-1;
        ll e = s+1;
        ll cnt = m % e, rc = e - cnt;
        ll R = (m/e) * (m/e) * rc + (m/e+1) * (m/e+1) * cnt;
        ans = max(ans, L - R);
    }
    cout << ans << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(1)solve();
}