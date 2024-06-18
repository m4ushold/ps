#include <bits/stdc++.h>
using namespace std;

char A[2020][2020], B[2020][2020];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        cin >> A[i][j];
        if(A[i][j]=='O') v.push_back({i,j});
    }

    memset(B, 1, sizeof B);
    for(auto [x,y]:v) {
        for(int i=x-1;i;i--) {
            if(A[i][y]!='.') break;
            B[i][y]=0;
        }
        for(int i=x+1;i<=n;i++) {
            if(A[i][y]!='.') break;
            B[i][y]=0;
        }
        for(int i=y+1;i<=n;i++) {
            if(A[x][i]!='.') break;
            B[x][i]=0;
        }
        for(int i=y-1;i;i--) {
            if(A[x][i]!='.') break;
            B[x][i]=0;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(A[i][j]=='.') cout << (B[i][j] ? "B" : ".");
            else cout << A[i][j];
        }
        cout << "\n";
    }
    return 0;
}