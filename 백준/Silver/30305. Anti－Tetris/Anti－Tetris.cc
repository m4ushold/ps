#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M;
char A[1010][1010], B[1010][1010];

bool chk() {
    for(int i=1;i<N;i++) {
        for(int j=1;j<=M;j++) if(A[i][j] == '#' && A[i+1][j] == '.') {
            return 0;
        }
    }
    return 1;
}

void rotate() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            B[j][N-i+1]=A[i][j];
        }
    }
    swap(N,M);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            A[i][j]=B[i][j];
        }
    }
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) cin >> A[i][j], A[i][j] = (A[i][j] == '.' ? '#' : '.');
    }
    for(int i=0;i<4;i++) {
        if(chk()) {
            cout << N << ' ' << M << '\n';
            for(int j=1;j<=N;j++) {
                for(int k=1;k<=M;k++) cout << A[j][k];
                cout << '\n';
            }
            return;
        }
        rotate();
    }
    cout << "impossible\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}