#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll n,m,k,d; cin >> n >> m >> k >> d;
    ll b=2*d/(k*n*m*(m-1) + m*m*n*(n-1));
    if(b) cout << m*(m-1)*n*k*b/2 + m*m*n*(n-1)*b/2;
    else cout << -1;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}