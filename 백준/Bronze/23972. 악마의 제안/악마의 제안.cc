#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll k, n; cin >> k >> n;
    if(n==1) cout << -1;
    else {
        ll dap=k*n/(n-1);
        if(k*n%(n-1)) dap++;
        cout << dap;
    }
    return 0;
}