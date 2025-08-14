#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, A[33][33], B[33][33];

void sol(int tc) {
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int a,b; cin >> a >> b, B[a][b]=1;
    }

    A[0][0]=1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<=i;j++) A[i+1][j]+=A[i][j], A[i+1][j+1]=A[i][j];
        int cnt=0;
        for(int j=0;j<N;j++) cnt+=B[i+1][j];

        if(cnt>1) {
            cout << 0;
            return;
        } else if(cnt==1) {
            for(int j=0;j<=i+1;j++) A[i+1][j]*=B[i+1][j];
        }
        
    }

    ll sum=0;
    for(int j=0;j<=N;j++) sum+=A[N-1][j];
    cout << sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}