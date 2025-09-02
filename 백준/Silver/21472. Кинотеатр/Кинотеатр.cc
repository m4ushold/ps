#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}

void sol(int tc) {
    int a,b; cin >> a >> b;
    cout << gcd(a-1,b-1)+1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}