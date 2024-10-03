#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int T;
ll N,M,k,D;

void sol() {
    ll n,m,k,d; cin >> n >> m >> k >> d;
    int b=0;
    while(n*m*(b+1)*(k*(m-1)+m*(n-1))<=2*d) b++;
    if(b<=1) cout << "-1\n";
    else cout << n*m*b*(k*(m-1)+m*(n-1))/2 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}