#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    ll g=0, l=1;
    for(ll i=0,a;i<n;i++) cin >> a, l=lcm(l,a);
    for(ll i=0,a;i<m;i++) cin >> a, g=gcd(g,a);
    if(g<l || g%l) return cout << 0, 0;
    ll a=g/l, dap=0;
    for(ll i=1;i*i<=a;i++) {
        if(a%i==0) {
            dap+=2;
            if(i==a/i) dap--;
        }
    }
    cout << dap;
    return 0;
}