#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin >> n >> m;
    ll dap=0;
    for(int i=1;i<=n;i++) {
        dap=(dap+pw(pw(i,m),MOD-2))%MOD;
        cout << dap << ' ';
    }
    return 0;
}