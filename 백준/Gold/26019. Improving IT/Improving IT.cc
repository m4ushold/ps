#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<ll>dp(n+2, 1e18);
    vector<vector<ll>>A(n+1, vector<ll>(m+1));
    for(int s=1; s<=n; s++){
        for(int e=0; e<=min(m, n-s+1); e++)cin >> A[s][e];
    }
    dp[1] = 0;
    for(int s=2; s<=n+1; s++){
        for(int e=max(1, s-m); e<s; e++)dp[s] = min(dp[s], dp[e] + A[e][0] - A[e][s-e]);
    }
    cout << dp[n+1];
}