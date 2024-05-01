#include <bits/stdc++.h>
using namespace std;

int N, K, A[101], dp[10101];

int main(void)
{
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> A[i]; 
    dp[0]=1;

    for(int i=1;i<=N;i++) {
        for(int j=0;j<=K;j++) {
            if(j-A[i]>=0) dp[j] += dp[j-A[i]];
        }
    }
    cout << dp[K] << '\n';
    return 0;
}