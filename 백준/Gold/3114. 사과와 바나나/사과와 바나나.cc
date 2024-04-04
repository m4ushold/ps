#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, A[1515][1515], B[1515][1515], D[1515][1515];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        char c; cin >> c;
        if(c=='A') cin >> A[i][j];
        else cin >> B[i][j];
        A[i][j]+=A[i-1][j];
        B[i][j]+=B[i-1][j];
    }
    
    for(int i=1;i<=N;i++) D[i][1]=A[N][1]-A[i][1];
    for(int j=1;j<=M;j++) D[1][j]=D[1][j-1]+A[N][j]-A[1][j];

    for(int j=2;j<=M;j++) for(int i=2;i<=N;i++) {
        D[i][j] = max(D[i][j-1],D[i-1][j-1]) + B[i-1][j] + A[N][j]-A[i][j];
        D[i][j] = max(D[i][j], D[i-1][j]-(A[i][j]-A[i-1][j]));
    }
    cout << D[N][M];
    return 0;
}