#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n; cin >> n;
    vector<ll> blue(n);
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) {
        int c; cin >> c;
        blue[i]+=c, blue[j]+=c;
    }
    ll ans=n*(n-1)*(n-2)/6, sum=0;
    for(ll i:blue) sum += i * (n-1-i);
    cout << ans-sum/2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}