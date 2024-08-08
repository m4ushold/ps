#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    if(n>=m) {cout << 0; return 0;}

    ll a=1;
    for(int i=1;i<=n;i++) a=a*i%m;
    cout << a;
    return 0;
}