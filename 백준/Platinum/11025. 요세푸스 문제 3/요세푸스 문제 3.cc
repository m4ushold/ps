#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,dap=0; cin >> n >> k;
    for(int i=1;i<=n;i++) dap=(k+dap)%i;
    cout << dap+1;
    return 0;
}