#include <bits/stdc++.h>
using namespace std;

int N, M, D[505][505];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> D[i][j];

    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
        }
    }
    for(int i=0,s,e,w;i<M;i++) {
        cin >> s >> e >> w;
        cout << (D[s][e]<=w ? "Enjoy other party\n" : "Stay here\n");
    }
    return 0;
}