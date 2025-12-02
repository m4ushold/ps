#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
void sol(int tc) {
    int x,y,p,a,b; cin >> x >> y >> p >> a >> b;
    p+=b*(y-1);
    ll ans=0;
    while(x--) ans+=p, p-=a;
    cout << ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}