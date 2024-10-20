#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, D[33][33];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> D[i][j];
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        D[i][j] += max(D[i-1][j], D[i][j-1])<<1;
    }
    cout << D[N][N];
    return 0;
}