#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    int cnt=0;
    for(ll i=1;i*i<=n;i++) cnt++;
    cout << cnt;
    return 0;
}