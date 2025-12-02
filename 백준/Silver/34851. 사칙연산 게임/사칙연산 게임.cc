#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
constexpr int mod = 1e9+7;
 
void sol(int tc) {
    int n; cin >> n;
    vector<ll> v(n+1);
    for(ll &i:v) cin >> i;
    ll ans=max(v[0]+v[1],v[0]*v[1])%mod;
    for(int i=2;i<=n;i++) {
        if(v[i]==1) ans=(ans+1)%mod;
        else ans=ans*v[i]%mod;
    }
    cout << ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}