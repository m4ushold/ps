#include <bits/stdc++.h>
using namespace std;

int R, C, H, W, A[3030][3030], B[3030][3030];

bool f(int m) {
    for(int i=1;i<=R;i++) for(int j=1,t;j<=C;j++) {
        t=(A[i][j]>m)-(A[i][j]<m);
        B[i][j]=t+B[i][j-1]+B[i-1][j]-B[i-1][j-1];
    }

    for(int i=H;i<=R;i++) for(int j=W;j<=C;j++) {
        if(B[i][j]-B[i][j-W]-B[i-H][j]+B[i-H][j-W] <=0 ) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> H >> W;
    for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) cin >> A[i][j];

    int s=1,e=R*C;
    while(s<e) {
        int m=s+e>>1;
        if(f(m)) e=m;
        else s=m+1;
    }
    cout << e;

    return 0;
}