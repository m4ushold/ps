#include <bits/stdc++.h>
using namespace std;

int N, A[505], DP[505][505], MN[505][505];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    memset(DP,0x3f,sizeof(DP));
    memset(MN,0x3f,sizeof(MN));
    for(int i=1;i<=N;i++) cin >> A[i];
    DP[1][1]=0;
    MN[1][1]=A[1];
    for(int i=2;i<=N;i++) {
        DP[i][i]=0, DP[i-1][i]=abs(A[i-1]-A[i]);
        MN[i][i]=A[i], MN[i-1][i]=min(A[i-1],A[i]);
    }

    for(int d=2;d<=N;d++) {
        for(int i=1;i+d-1<=N;i++) {
            int j=i+d-1;
            for(int k=i;k<j;k++) {
                DP[i][j]=min(DP[i][j],DP[i][k]+DP[k+1][j]+abs(MN[i][k]-MN[k+1][j]));
                MN[i][j]=min({MN[i][j], MN[i][k], MN[k+1][j]});
            }
        }
    }
    cout << DP[1][N];
    return 0;
}