#include <bits/stdc++.h>
using namespace std;

int N, M, D[101][101];
char A[101][101];
vector<pair<int,int>> dir({{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}});

int sq(int x) {return x*x;}
bool bound(int x, int y) {return 1<=min(x,y) && x<=N && y<=M;}
int dijk(int x, int y) {
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) D[i][j]=1e9;
    D[x][y]=0;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<>> pq;
    pq.push({0,x,y});
    while(pq.size()) {
        auto [c,x,y]=pq.top(); pq.pop();
        for(auto [dx,dy]:dir) {
            int nx=x+dx, ny=y+dy;
            if(bound(nx, ny) && A[nx][ny]!='#' && sq(abs(A[x][y]-A[nx][ny])+1) + D[x][y] < D[nx][ny]) {
                D[nx][ny] = sq(abs(A[x][y]-A[nx][ny])+1) + D[x][y];
                pq.push({D[nx][ny],nx,ny});
            }
        }
    }

    int dap=0,mx=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]!='#' && A[i][j]>mx) mx=A[i][j], dap=D[i][j];
    return dap;
}

void sol() {
    cin >> N >> M;
    int mx=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int x,y; cin >> x >> y;
    x++, y++;
    cout << dijk(x,y) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}