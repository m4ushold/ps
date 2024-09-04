#include <bits/stdc++.h>
using namespace std;

int N, M, A[1010][1010];
vector<pair<int,int>> dir({{1,0}, {0,1}, {-1,0}, {0,-1}});

bool bound(int x, int y) {return 1<=min(x,y) && x<=N && y<=M;}

int sol() {
    memset(A, 0, sizeof(A));
    cin >> M >> N;
    queue<tuple<int,int,int,int>> q;
    int x,y;

    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        char c; cin >> c;
        if(c=='@') x=i,y=j;
        else if(c=='*') q.push({i,j,1,0}), A[i][j]=1;
        else if(c=='#') A[i][j]=1;
    }
    q.push({x,y,0,1});

    while(q.size()) {
        auto [i,j,f,d]=q.front(); q.pop();
        if(f==0 && (i==1 || i==N || j==1 || j==M)) return cout << d << '\n', 0;
        A[i][j]=1;
        for(auto [dx,dy]:dir) if(bound(i+dx,j+dy) && !A[i+dx][j+dy]) {
            A[i+dx][j+dy]=1, q.push({i+dx,j+dy,f,d+1});
        }
    }
    return cout << "IMPOSSIBLE\n", 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}