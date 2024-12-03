#include <bits/stdc++.h>
using namespace std;

int n, A[11][11];

bool bound(int x, int y) {return 0<=min(x,y) && max(x,y)<n;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    string s; cin >> s;

    int x=0,y=0;
    for(char c:s) {
        if(c=='D' && bound(x+1,y)) A[x][y] |= 1, x++, A[x][y] |= 1;
        if(c=='R' && bound(x,y+1)) A[x][y] |= 2, y++, A[x][y] |= 2;
        if(c=='L' && bound(x,y-1)) A[x][y] |= 2, y--, A[x][y] |= 2;
        if(c=='U' && bound(x-1,y)) A[x][y] |= 1, x--, A[x][y] |= 1;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(A[i][j]==2) cout << '-';
            else if(A[i][j]==1) cout << '|';
            else if(A[i][j]) cout << '+';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}