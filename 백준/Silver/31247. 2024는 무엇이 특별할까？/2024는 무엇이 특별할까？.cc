#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n, k, a; cin >> n >> k;
        a=1LL<<k;
        if(k==0) cout << (n+1>>1) << '\n';
        else if(k==63) cout << n/a << '\n';
        else if(k>62) cout << "0\n";
        else cout << n/a - n/(a*2) << '\n';
    }
    return 0;
}