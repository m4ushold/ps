#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n,m; cin >> n >> m;
    cout << (n - m) * m + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}