#include <bits/stdc++.h>
using namespace std;

int N, M, W[55][55], C[55][55], WW[55][55], CC[55][55];
vector<pair<int,int>> dir({
    {0,0},
    {0,-1},{-1,-1},{-1,0},{-1,1},
    {0,1},{1,1},{1,0},{1,-1}
}), di({
    {1,1},{-1,-1},{1,-1},{-1,1}
});

int f(int x) {
    return ((x-1)%N+N)%N+1;
}

void move(int d, int s) {
    // move cloud
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(C[i][j]) {
        int x=i+dir[d].first*s, y=j+dir[d].second*s;
        x=f(x), y=f(y);
        CC[x][y]=1;
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) C[i][j]=CC[i][j];
    memset(CC, 0, sizeof(CC));

    // rain
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) W[i][j]+=C[i][j];

    // copy bug magic
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        WW[i][j]=W[i][j];
        if(C[i][j]) {
            for(auto [dx,dy]:di) if(0<min(i+dx,j+dy) && max(i+dx,j+dy)<=N) {
                if(W[i+dx][j+dy]) WW[i][j]++;
            }
        }
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) W[i][j]=WW[i][j];

    // make cloud
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(W[i][j]>1 && !C[i][j]) {
        W[i][j]-=2, CC[i][j]=1;
    }
    memset(C, 0, sizeof(C));
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) C[i][j]=CC[i][j];
    memset(CC, 0, sizeof(CC));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    C[N][1] = C[N][2] = C[N-1][1] = C[N-1][2] = 1;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> W[i][j];

    for(int i=1,d,s;i<=M;i++) {
        cin >> d >> s;
        move(d,s);
    }
    int dap=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) dap+=W[i][j];
    cout << dap;
    return 0;
}