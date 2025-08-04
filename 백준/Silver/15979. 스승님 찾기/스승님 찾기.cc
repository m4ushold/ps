#include <bits/stdc++.h>
using namespace std;

int gcd(int n, int m) {
    if(m==0) return n;
    return gcd(m,n%m);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    n=abs(n), m=abs(m);
    if(n==0 && m==0) cout << 0;
    else if(gcd(n,m)==1) cout << 1;
    else cout << 2;
    return 0;
}