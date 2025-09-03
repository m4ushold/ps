#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, A[303][303], R[303][303], C[303][303], D[303][303][303], P[303][303][303];

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        R[i][j]+=R[i][j-1]+A[i][j];
        C[i][j]+=C[i-1][j]+A[i][j];
    }
    for(int e=1;e<=N;e++) for(int s=1;s<e;s++) {
        D[s][e][0]=LLONG_MIN;
        P[s][e][0]=1;
        for(int j=1;j<=M;j++) {
            D[s][e][j]=-R[s][j]-R[e][j]+C[e][j]-C[s-1][j];
            // cout << s << ' ' << e << " " << j << " : " << D[s][e][j] << endl;
            if(D[s][e][j] < D[s][e][j-1]) P[s][e][j]=P[s][e][j-1], D[s][e][j] = D[s][e][j-1];
            else P[s][e][j]=j;
        }
    }

    ll mx=LLONG_MIN;
    array<int, 4> res={1,1,2,2};
    for(int i=1;i<=N;i++) for(int j=2;j<=M;j++) {
        for(int s=1;s<i;s++) {
            ll tmp = R[i][j] + R[s][j] + C[i][j] - C[s-1][j] + D[s][i][j-1] - A[i][j] - A[s][j];
            // cout << i << ' ' << j << " : " << R[i][j] + R[s][j] + C[i][j] - A[i][j] - A[s][j] << ' ' << D[s][i][j-1] << '\n';
            // cout << tmp << endl;
            if(mx < tmp) {
                mx = tmp;
                res={s,(int)P[s][i][j-1],i,j};
            }
        }
    }
    cout << mx << '\n';
    for(int i=0;i<4;i++) cout << res[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}