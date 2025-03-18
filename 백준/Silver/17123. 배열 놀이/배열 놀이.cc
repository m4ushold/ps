#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll T, N, M, A[1010][1010];

void sol() {
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    for(int i=1;i<=N;i++) for(int j=N;j;j--) A[i][j] -= A[i][j-1];
    for(int t=0;t<M;t++) {
        int r1,c1,r2,c2,v; cin >> r1 >> c1 >> r2 >> c2 >> v;
        for(int i=r1;i<=r2;i++) A[i][c1]+=v, A[i][c2+1]-=v;
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) A[i][j]+=A[i][j-1];

    for(int i=1;i<=N;i++) {
        ll sum=0;
        for(int j=1;j<=N;j++) sum+=A[i][j];
        cout << sum << ' ';
    }
    cout << '\n';
    for(int i=1;i<=N;i++) {
        ll sum=0;
        for(int j=1;j<=N;j++) sum+=A[j][i];
        cout << sum << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while(T--) sol();
    return 0;
}