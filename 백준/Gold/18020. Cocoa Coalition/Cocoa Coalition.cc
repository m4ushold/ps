#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

bool chk(ll n, ll m, ll a) {
    for(ll i=1;i*i<=a;i++) {
        if(a%i==0) {
            ll x=i, y=a/i;
            if(x<n && y<m) return 1;
            if(y<n && x<m) return 1;
        }
    }

    ll b = n*m-a;
    for(ll i=1;i*i<=b;i++) {
        if(b%i==0) {
            ll x=i, y=b/i;
            if(x<n && y<m) return 1;
            if(y<n && x<m) return 1;
        }
    }

    return 0;
}

void sol(int tc) {
    ll n,m,a; cin >> n >> m >> a;
    if(a%n == 0 || a%m == 0) cout << 1;
    else if(chk(n,m,a)) cout << 2;
    else cout << 3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}