#include <bits/stdc++.h>
using namespace std;

int N, M, A[505][505], D[505][505];
vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});

bool bound(int x, int y) { return 1<=min(x,y) && x<=N && y<=M; }

int dfs(int x, int y) {
    if(x==N && y==M) return 1;
    if(D[x][y]!=-1) return D[x][y];
    D[x][y]=0;
    for(auto [i,j]:v) if(bound(x+i, y+j) && A[x][y] > A[x+i][y+j]) D[x][y]+=dfs(x+i, y+j);
    return D[x][y];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j], D[i][j]=-1;
    cout << dfs(1,1);
    return 0;
}