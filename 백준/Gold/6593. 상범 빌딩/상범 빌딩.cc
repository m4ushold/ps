#include <bits/stdc++.h>
using namespace std;

int N, M, K, A[101][101][101];
vector<tuple<int,int,int>> v={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};

bool chk(int x, int y, int z) { return 0<min({x,y,z}) && x<=N && y<=M && z<=K && A[x][y][z]!=1; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> N >> M >> K && N) {
        memset(A, 0, sizeof(A));
        queue<tuple<int,int,int,int>> q;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) for(int k=1;k<=K;k++) {
            char c; cin >> c;
            if(c=='S') q.push({i,j,k,0});
            else if(c=='#') A[i][j][k]=1;
            else if(c=='E') A[i][j][k]=2;
        }

        int f=1;
        while(q.size()) {
            auto [i,j,k,d]=q.front(); q.pop();
            if(A[i][j][k]==2) {cout << "Escaped in " << d << " minute(s).\n", f=0; break;}
            for(auto [dx,dy,dz]:v) if(chk(i+dx,j+dy,k+dz)) {
                q.push({i+dx,j+dy,k+dz,d+1});
                if(!A[i+dx][j+dy][k+dz]) A[i+dx][j+dy][k+dz]=1;
            }
        }
        if(f) cout << "Trapped!\n";
    }
    return 0;
}