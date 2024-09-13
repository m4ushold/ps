#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void sol() {
    ll a,b,n,dp[11]={}; cin >> a >> b >> n;
    n=(n-1)%6+1;
    dp[1]=(a+MOD)%MOD, dp[2]=(b+MOD)%MOD;
    for(int i=3;i<=6;i++) dp[i]=((dp[i-1]-dp[i-2])%MOD+MOD)%MOD;
    cout << dp[n]%MOD << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}