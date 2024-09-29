#include <bits/stdc++.h>
using namespace std;

int N, M, A[505][505], B[505][505];
vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});

bool bound(int x, int y) {return 1<=min(x,y) && x<=N && y<=M;}

int dfs(int x, int y) {
    int res=1;
    B[x][y]=1;
    for(auto [dx,dy]:v) if(bound(x+dx,y+dy) && !B[x+dx][y+dy] && A[x+dx][y+dy]) res+=dfs(x+dx,y+dy);
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int mx=0, cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        if(A[i][j] && !B[i][j]) mx=max(mx,dfs(i,j)), cnt++;
    }
    cout << cnt << '\n' << mx;
    return 0;
}