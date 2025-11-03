#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int mod = 1e9+7;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n>>=1;
    }
    return res;
}

int max(ll x, ll y, ll p, ll q) {
    if((x+2)*y >= x*(y+2) && (x+2)*q >= p*x) return 0;
    else if((y+2)*x >= y*(x+2) && (y+2)*q >= p*y) return 1;
    return 2;
}

void sol(int tc) {
    ll p,q,n; cin >> p >> q >> n;
    ll x=1,y=1,z=0,a=p*pw(q,mod-2)%mod, it=pw(2,mod-2);

    cout << 0 << ' ' << 1 << ' ';
    ll ans=1;
    for(int i=2;i<n;i++) {
        ll r = max(x,y,p,q);
        if(r==0) ans=ans*(x+2)%mod*pw(x,mod-2)%mod, x++;
        else if(r==1) ans=ans*(y+2)%mod*pw(y,mod-2)%mod, y++;
        else ans=ans*a%mod;
        cout << ans << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}