#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9;
ll N, K, D[202][202];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<=N;i++) D[i][1]=1;
    for(int k=2;k<=K;k++) for(int n=0;n<=N;n++) {
        for(int i=0;i<=n;i++) D[n][k]=(D[n][k]+D[n-i][k-1])%MOD;
    }
    cout << D[N][K];
    return 0;
}