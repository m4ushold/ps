#include <bits/stdc++.h>
using namespace std;

int N, M, D[55][55];
char A[55][55];
vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});

bool bound(int x, int y) {return 1<=min(x,y) && x<=N && y<=M;}

int bfs(int i, int j) {
    memset(D, -1, sizeof(D));
    queue<pair<int,int>> q; q.push({i,j});
    D[i][j]=0;
    while(q.size()) {
        auto [x,y]=q.front(); q.pop();
        for(auto [dx,dy]:v) if(bound(x+dx,y+dy) && A[x+dx][y+dy]=='L' && D[x+dx][y+dy]==-1) {
            q.push({x+dx,y+dy});
            D[x+dx][y+dy]=D[x][y]+1;
        }
    }
    int mx=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) mx=max(mx,D[i][j]);
    return mx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int mx=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]=='L') mx=max(mx,bfs(i,j));
    cout << mx;
    return 0;
}