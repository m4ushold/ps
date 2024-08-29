#include <bits/stdc++.h>
using namespace std;

int W, H, N, A[1010][1010], D[1010][1010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> W >> H >> N;
    for(int i=1;i<=W;i++) for(int j=1;j<=H;j++) cin >> A[i][j];
    D[1][1]=N-1;
    for(int i=1;i<=W;i++) for(int j=1;j<=H;j++) {
        if(!A[i][j]) {
            D[i+1][j] += D[i][j]+1>>1;
            D[i][j+1] += D[i][j]>>1;
        } else {
            D[i+1][j] += D[i][j]>>1;
            D[i][j+1] += D[i][j]+1>>1;
        }
    }
    
    for(int i=1;i<=W;i++) for(int j=1;j<=H;j++) if(D[i][j]&1) A[i][j]^=1;

    int x=1,y=1;
    while(x<=W && y<=H) {
        if(A[x][y] == 1) y++;
        else x++;
    }
    cout << x << ' ' << y;
    return 0;
}