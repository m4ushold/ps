#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<17;
int N, dp[2][sz], A[1010], B[1010];

void sol() {
    cin >> N;
    int as=0, bs=0;
    for(int i=1;i<=N;i++) cin >> A[i] >> B[i], as+=A[i], bs+=B[i];
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=N;i++) {
        for(int j=1;j<sz;j++) {
            if(j-A[i]>=0) dp[i&1][j] = max(dp[~i&1][j], dp[~i&1][j-A[i]]+B[i]);
            else dp[i&1][j]=dp[~i&1][j];
        }
    }

    int mn=1e9;
    for(int i=1;i<sz;i++) {
        mn = min(mn, max(i, bs-dp[N&1][i]));
    }
    cout << mn << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}