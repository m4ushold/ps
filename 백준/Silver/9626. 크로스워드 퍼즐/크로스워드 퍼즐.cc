#include <bits/stdc++.h>
using namespace std;

int N, M, U, L, R, D;
char A[22][22];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> U >> L >> R >> D;
    for(int i=0;i<22;i++) for(int j=0;j<22;j++) A[i][j] = ((i+j)&1 ? '.' : '#');
    for(int i=U;i<U+N;i++) for(int j=L;j<L+M;j++) cin >> A[i][j];

    for(int i=0;i<U+D+N;i++) {
        for(int j=0;j<L+R+M;j++) cout << A[i][j];
        cout << '\n';
    }

    return 0;
}