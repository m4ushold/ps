#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
const int MOD = 1'000'000'007;
ll N, DP[1<<20][2]; // 1 : odd, 0 : even
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    DP[1][1] = 2, DP[1][0] = 24;
    cin >> N;
    for(int i=2;i<=N;i++) {
        DP[i][0] = (DP[i-1][0]*24%MOD + DP[i-1][1]*2%MOD)%MOD;
        DP[i][1] = (DP[i-1][0]*2%MOD + DP[i-1][1]*24%MOD)%MOD;
    }
    cout << DP[N][0];
    return 0;
}