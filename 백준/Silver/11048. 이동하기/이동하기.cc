#include <bits/stdc++.h>
using namespace std;

int N, M, A[1010][1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j], A[i][j]+=max({A[i-1][j],A[i-1][j-1],A[i][j-1]});
    cout << A[N][M];
    return 0;
}