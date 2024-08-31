#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll a,b; cin >> a >> b;
    while(a>1) {
        ll c=b/a+1;
        a=a*c-b, b*=c;
        ll g=gcd(a,b);
        a/=g, b/=g;
    }
    cout << b << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}