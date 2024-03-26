#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    ll dp[101]={1,1,2,4};
    for(int i=4;i<101;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}