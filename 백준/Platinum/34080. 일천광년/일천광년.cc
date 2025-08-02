#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n,x,y; cin >> n >> x >> y;
    ll a = n*y/(x+y), lb = n*y%(x+y), la=x+y-lb, b=a+1;
    cout << 1+(lb?1:0) << '\n';
    cout << a << ' ' << la << '\n';
    if(lb) cout << b << ' ' << lb << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}