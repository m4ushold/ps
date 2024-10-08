#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, A[303][303];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        A[i][j] += A[i][j-1] + A[i-1][j] - A[i-1][j-1];
    }
    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) for(int k=i;k;k--) for(int l=j;l;l--) {
        if(A[i][j] - A[i][l-1] - A[k-1][j] + A[k-1][l-1] == 10) {
            cnt++;
        } else if(A[i][j] - A[i][l-1] - A[k-1][j] + A[k-1][l-1] > 10) {
            break;
        }
    }
    cout << cnt;
    return 0;
}