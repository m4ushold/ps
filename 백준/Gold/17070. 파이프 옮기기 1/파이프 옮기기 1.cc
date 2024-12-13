#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A[20][20];
vector<array<int,2>> dir({{0,1},{1,0},{1,1}});

bool chk(int x, int y) {return 0<=min(x,y) && max(x,y)<N;}
int dfs(int x, int y, int t) {
    if(x==N-1 && y==N-1) return 1;
    int res=0;
    for(int i=0; i<3; i++) {
        if((t==0 && i==1) || (t==1 && i==0)) continue;
        auto [dx,dy] = dir[i];
        int nx=x+dx, ny=y+dy;
        if(!chk(nx,ny) || A[nx][ny]) continue;
        if(i==2 && (A[nx-1][ny] || A[nx][ny-1])) continue;
        res+=dfs(nx,ny,i);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
    cout << dfs(0,1,0);
    return 0;
}