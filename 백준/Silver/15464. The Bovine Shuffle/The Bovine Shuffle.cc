#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, I[101], A[4][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> I[i];
    for(int i=1;i<=N;i++) cin >> A[0][i];
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=N;j++) A[i][j] = A[i-1][I[j]];
    }
    for(int i=1;i<=N;i++) cout << A[3][i] << '\n';
    return 0;
}