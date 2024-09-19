#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, D[55][1010];

void sol() {
    cin >> N >> M;
    cout << D[N][M] << '\n';
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i=1;i<55;i++) for(int j=1;j<1010;j++) D[i][j]=1e9;
    for(int i=1;i<1010;i++) D[1][i]=i;

    for(int i=2;i<55;i++) {
        for(int j=1;j<1010;j++) {
            for(int k=1;k<=j;k++) {
                D[i][j] = min(D[i][j], 1+max(D[i-1][k-1], D[i][j-k]));
            }
        }
    }

    int t; cin >> t;
    while(t--) sol();
    return 0;
}