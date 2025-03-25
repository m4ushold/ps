#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n; cin >> n;
    ll res=0;
    for(ll i=1;i<=n;i++) res+=i*(i+1)/2;
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}