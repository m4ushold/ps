#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n; cin >> n;
    cout << ((n*(n+1))^(n+1)) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}