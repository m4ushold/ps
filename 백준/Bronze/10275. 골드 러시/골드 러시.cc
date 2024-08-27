#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n,a,b,s,dap=0;
        cin >> n >> a >> b;
        s=min(a,b);
        while(~s&1 && s>0) s/=2, dap++;
        cout << n-dap << '\n';
    }
    return 0;
}