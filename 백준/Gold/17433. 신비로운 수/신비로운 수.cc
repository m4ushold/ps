#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll a; cin >> a;
        vector<ll> v;
        for(ll i=1,b;i<n;i++) {
            cin >> b;
            v.push_back(abs(a-b));
            a=b;
        }
        ll g=0;
        for(ll i:v) g=gcd(i,g);
        if(!g) cout << "INFINITY\n";
        else cout << g << '\n';
    }
    return 0;
}