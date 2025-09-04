#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, A[101][101], R[101], C[101];

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> R[i];
    for(int i=1;i<=M;i++) cin >> C[i];
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) A[i][j]=min(R[i],C[j]);
    for(int i=1;i<=N;i++) {
        int mx=0;
        for(int j=1;j<=M;j++) mx=max(mx,A[i][j]);
        if(mx != R[i]) {
            cout << "impossible";
            return;
        }
    }
    for(int i=1;i<=M;i++) {
        int mx=0;
        for(int j=1;j<=N;j++) mx=max(mx,A[j][i]);
        if(mx != C[i]) {
            cout << "impossible";
            return;
        }
    }
    cout << "possible";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}