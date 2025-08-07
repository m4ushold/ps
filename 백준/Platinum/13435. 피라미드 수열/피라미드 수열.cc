#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[1010][1010];

ll gcd(ll n, ll m) {
    return m ? gcd(m, n%m) : n;
}

void sol(int tc) {
    ll n,m; cin >> n >> m;
    if(n==1 || m==1) {
        cout << max(n,m);
        return;
    }
    ll g = gcd(n-1,m-1), a=(n-1)/g, b=(m-1)/g;
    cout << a*b*(g-1) + (a+1)*(b+1)/2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}