#include <bits/stdc++.h>
using namespace std;

int N, DP[1<<17], W[22][22];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> W[i][j];
    string s; cin >> s;

    int mask=0;
    for(char c:s) mask = mask<<1 | (c=='Y');

    for(int i=0;i<(1<<N);i++) DP[i]=1e9;
    DP[mask]=0;

    for(int i=mask;i<(1<<N);i++) if((mask|i) == i) {
        for(int j=0;j<N;j++) for(int k=0;k<N;k++) {
            if(j!=k && (i&(1<<j)) && (i&(1<<k))) {
                DP[i] = min(DP[i], W[N-j-1][N-k-1]+DP[i^(1<<k)]);
            }
        }
    }

    int p, dap=1e9; cin >> p;
    for(int i=mask;i<(1<<N);i++) if(__popcount(i) >= p) dap=min(dap, DP[i]);

    cout << (dap==(int)1e9 ? -1 : dap);
    return 0;
}