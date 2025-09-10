#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, K, D[101][101010], A[101];

void sol(int tc) {
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=0;i<=N;i++) for(int j=0;j<101010;j++) D[i][j]=1e9;
    D[0][0]=0;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<101010;j++) {
            D[i][j]=D[i-1][j];
            if(j>=A[i]) D[i][j]=min(D[i][j], D[i-1][j-A[i]]+1);
        }
    }
    if(D[N][K]==1e9) cout << -1;
    else cout << D[N][K];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}