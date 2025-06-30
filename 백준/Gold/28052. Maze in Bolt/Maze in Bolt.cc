#include <bits/stdc++.h>
using namespace std;

int R, C, A[1010][101], B[1010][101];
char M[1010][101], N[101];
vector<pair<int,int>> dir({
    {1,0}, {0,1}, {-1,0}, {0,-1}
});

bool chk(int x, int y) {
    for(int i=0;i<C;i++) if(M[x][i]=='1' && N[(i+y)%C]=='1') return 0;
    return 1;
}

bool valid(int x, int y) {
    return 0<=min(x,y) && x<=R && y<C;
}

bool sol() {
    queue<pair<int,int>> q;
    q.push({0,0});
    while(q.size()) {
        auto [x,y] = q.front(); q.pop();
        for(auto [dx,dy]:dir) {
            if(dx) {
                if(valid(x+dx,y+dy) && A[x+dx][y+dy] && B[x+dx][y+dy]==0) {
                    B[x+dx][y+dy]=1;
                    q.push({x+dx,y+dy});
                }
            } else {
                int nx = x, ny = y+dy;
                if(ny == -1) ny = C-1;
                if(ny == C) ny = 0;
                if(A[nx][ny] && B[nx][ny]==0) {
                    B[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    for(int i=0;i<C;i++) if(B[R][i]) return 1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> C;
    cin >> N;
    for(int i=0;i<R;i++) cin >> M[i];

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) A[i+1][j] = chk(i, j);
    }
    for(int i=0;i<C;i++) A[0][i]=1;

    int ans = sol();

    memset(B, 0, sizeof(B));
    reverse(N, N+C);
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) A[i+1][j] = chk(i, j);
    }
    ans |= sol();
    cout << (ans ? 'Y' : 'N');
    return 0;
}