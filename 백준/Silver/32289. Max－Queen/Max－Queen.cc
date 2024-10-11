#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin >> n >> m;
    ll ans=(n-2)*(m-2)*4 + (n+m-4)*5 + 6;
    cout << ans;
    return 0;
}