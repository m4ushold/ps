#include <bits/stdc++.h>
using namespace std;

int N, M, A[303][303];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        A[i][j] += max(A[i][j-1], A[i-1][j]);
    }
    cout << A[N][M];
    return 0;
}