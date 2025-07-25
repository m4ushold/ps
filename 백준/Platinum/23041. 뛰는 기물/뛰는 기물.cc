#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    ll g = gcd(n,m);
    n/=g, m/=g;
    cout << ((n+m)&1 ? 1 : 2) * g * g;
    return 0;
}