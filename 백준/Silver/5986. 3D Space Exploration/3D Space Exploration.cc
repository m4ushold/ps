#include <bits/stdc++.h>
using namespace std;

int N, A[101][101][101], B[101][101][101];
vector<tuple<int,int,int>> v({
    {1,0,0}, {0,1,0}, {0,0,1},
    {-1,0,0}, {0,-1,0}, {0,0,-1}
});

bool bound(int x, int y, int z) { return 1<=min({x,y,z}) && max({x,y,z})<=N; }
void dfs(int i, int j, int k) {
    if(B[i][j][k]) return;
    B[i][j][k]=1;
    for(auto [x,y,z]:v) {
        if(bound(i+x,j+y,k+z) && !B[i+x][j+y][k+z] && A[i+x][j+y][k+z]) dfs(i+x,j+y,k+z);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) {
        char c; cin >> c;
        A[i][j][k]=c=='*';
    }

    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) if(!B[i][j][k] && A[i][j][k]) {
        dfs(i,j,k);
        cnt++;
    }
    cout << cnt;
    return 0;
}