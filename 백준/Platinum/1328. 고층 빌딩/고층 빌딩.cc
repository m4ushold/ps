#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll N, L, R, D[101][101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    D[1][1][1]=1;
    for(int n=2;n<=N;n++) for(int l=1;l<=n;l++) for(int r=1;r<=n;r++) {
        D[n][l][r] = (D[n-1][l-1][r] + D[n-1][l][r-1] + D[n-1][l][r]*(n-2)%MOD)%MOD;
    }
    cout << D[N][L][R];
    return 0;
}