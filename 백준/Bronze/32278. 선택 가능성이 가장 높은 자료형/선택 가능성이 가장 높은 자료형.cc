#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    if(SHRT_MIN <= n && n<=SHRT_MAX) cout << "short";
    else if(INT_MIN<=n && n<=INT_MAX) cout << "int";
    else cout << "long long";
    return 0;
}