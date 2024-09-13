#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll len(ll n) { return (1LL << (n+2)) - 3; }
ll p(ll n) { return (1LL << (n+1)) - 1; }

ll recur(ll n, ll x) {
    if(n == 0 && x <= 0) return 0;
    if(n == 0) return 1;

    if(len(n)/2 > x) return recur(n-1, x-1);
    else if(len(n)/2 == x) return p(n-1);
    else if(len(n)/2 == x-1) return p(n-1) + 1;
    else return recur(n-1, x-2-len(n-1)) + 1 + p(n-1);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x, l;
    cin >> n >> x;
    cout << recur(n, x) << '\n';
    return 0;
}