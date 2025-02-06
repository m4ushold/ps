#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll pw(ll a, ll n) {
    ll res=1;
    if(n<0) return res;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t,n; cin >> t;
    while(t--) cin >> n, cout << pw(2,n-2) << '\n';
    return 0;
}