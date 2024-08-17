#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,dap=0;
    cin >> n;
    while(n--) {
        ll a,b; cin >> a >> b, b=a+b-1;
        for (ll i = a; i < a + 4 - a % 4; i++) dap ^= i;
        for (ll i = b - b % 4; i <= b; i++) dap ^= i;
    }
    cout << (dap ? "koosaga" : "cubelover");
    return 0;
}