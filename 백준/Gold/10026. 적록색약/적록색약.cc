#include <bits/stdc++.h>
using namespace std;

int N, A[101][101], B[101][101], C[101][101];

bool chk(int x, int y) { return 0<min(x,y) && max(x,y)<=N; }

void g(int i, int j) {
    vector<pair<int,int>> v({{-1,0}, {1,0}, {0,-1}, {0,1}});
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()) {
        auto [x,y]=q.front(); q.pop();
        C[x][y]=1;
        for(auto [dx,dy]:v) {
            if(chk(x+dx,y+dy) && !C[x+dx][y+dy] && A[i][j]==A[x+dx][y+dy]) q.push({x+dx,y+dy}), C[x+dx][y+dy]=1;
        }
    }
}

int f(int a) {    
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(a) A[i][j]=B[i][j];
        C[i][j]=0;
    }

    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(!C[i][j]) ++cnt, g(i,j);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        char c; cin >> c;
        if(c=='R') A[i][j]=B[i][j]=1;
        else if(c=='B') A[i][j]=B[i][j]=2;
        else A[i][j]=3,B[i][j]=1;
    }

    cout << f(0) << ' ' << f(1);
    return 0;
}