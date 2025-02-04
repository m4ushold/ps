#include <bits/stdc++.h>
using namespace std;

const int sz=1<<22;
int N, K, P[sz], S[sz], B[2020][2020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
int idx(int x, int y) {return (x-1)*N+y;}
bool chk(int x, int y) {return 1<=min(x,y) && max(x,y)<=N;}

vector<pair<int,int>> dir({{1,0},{0,1},{-1,0},{0,-1}});

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    init(N*N);
    queue<pair<int,int>> q;
    for(int i=0,x,y;i<K;i++) {
        cin >> x >> y;
        q.push({x,y}), S[idx(x,y)]=1, B[x][y]=1;
        for(auto [dx,dy]:dir) if(chk(x+dx,y+dy) && B[x+dx][y+dy]) Union(idx(x,y),idx(x+dx,y+dy));
        if(S[Find(idx(x,y))] == K) return cout << 0, 0;
    }

    while(q.size()) {
        auto [x,y]=q.front(); q.pop();
        for(auto [dx,dy]:dir) if(chk(x+dx,y+dy)) {
            int nx=x+dx, ny=y+dy;
            if(B[nx][ny]) {
                Union(idx(x,y),idx(nx,ny));
            } else {
                B[nx][ny] = B[x][y]+1;
                q.push({nx,ny});
                for(auto [ddx,ddy]:dir) if(chk(nx+ddx,ny+ddy) && B[nx+ddx][ny+ddy]) Union(idx(nx,ny), idx(nx+ddx,ny+ddy));
            }
        }
        if(S[Find(idx(x,y))] == K) return cout << B[x][y], 0;
    }
    return 0;
}