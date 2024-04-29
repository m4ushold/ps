#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> v(n);
        for(ll &i:v) cin >> i;
        int a; cin >> a;
        vector<ll> dp(a+1);
        dp[0]=1;
        for(ll i:v) for(int k=1;k<=a;k++) if(k-i>=0) dp[k]+=dp[k-i];
        cout << dp[a] << '\n';
    }
    return 0;
}