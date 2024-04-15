#include <bits/stdc++.h>
using namespace std;

int N, M, A[11][11], B[11][11];

void cpy() { for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) B[i][j]=A[i][j]; }
int cnt() { 
    int res=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) res+=!B[i][j];
    return res;
}
bool bound(int x, int y) { return 1<=min(x,y) && x<=N && y<=M; }

void bfs() {
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(B[i][j]==2) q.push({i,j});
    while(!q.empty()) {
        auto [i,j]=q.front(); q.pop();
        B[i][j]=2;
        vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});
        for(auto [x,y]:v) {
            if(bound(i+x, j+y) && B[i+x][j+y]==0) q.push({i+x,j+y});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vector<pair<int,int>> v;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        if(!A[i][j]) v.emplace_back(i,j);
    }

    int dap=0, n=v.size();
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
        cpy();
        B[v[i].first][v[i].second] = B[v[j].first][v[j].second] = B[v[k].first][v[k].second] = 1;
        bfs();
        dap=max(dap, cnt());
    }
    cout << dap;
    return 0;
}