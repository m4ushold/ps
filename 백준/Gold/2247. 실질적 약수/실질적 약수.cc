#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MOD=1'000'000;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll dap=0;
    for(int i=2; i<=n/2; i++) {
        dap = (dap+i*(n/i-1)%MOD)%MOD;
    }
    cout << dap;
    return 0;
}