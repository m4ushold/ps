#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[101][101], D[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    D[1][1]=1;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[i][j]) {
        if(i+A[i][j]<=N) D[i+A[i][j]][j] += D[i][j];
        if(j+A[i][j]<=N) D[i][j+A[i][j]] += D[i][j];
    }
    cout << D[N][N];
}