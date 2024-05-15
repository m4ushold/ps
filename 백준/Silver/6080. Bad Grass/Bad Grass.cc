#include <bits/stdc++.h>
using namespace std;

int N, M, A[1010][1010];
vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}});

bool bound(int i, int j) { return 1<=min(i,j) && i<=N && j<=M; }

void dfs(int i, int j) {
    if(!A[i][j]) return;
    A[i][j]=0;
    for(auto [x,y]:v) if(bound(i+x, j+y) && A[i+x][j+y]) dfs(i+x,j+y);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];

    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]) dfs(i,j), cnt++;
    cout << cnt << '\n';
    return 0;
}