#include <bits/stdc++.h>
using namespace std;

int N, A[101][101], B[101][101];
vector<pair<int,int>> d({{1,0},{0,1},{-1,0},{0,-1}});

bool bound(int x, int y) {return 1<=min(x,y) && max(x,y)<=N;}

bool bfs(int s, int e) {
    if(A[1][1] < s || e < A[1][1]) return 0;

    memset(B, 0, sizeof(B));
    queue<pair<int,int>> q; q.push({1,1});
    B[1][1]=1;
    while(q.size()) {
        auto [x,y]=q.front(); q.pop();
        if(x==N && y==N) return 1;
        for(auto [dx,dy]:d) if(bound(x+dx, y+dy) && !B[x+dx][y+dy] && s<=A[x+dx][y+dy] && A[x+dx][y+dy]<=e) {
            q.push({x+dx,y+dy}), B[x+dx][y+dy]=1;
        }
    }
    return 0;
}

bool chk(int m) {
    for(int i=0;i+m<=200;i++) {
        if(bfs(i,i+m)) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    int l=0, r=200;
    while(l+1<r) {
        int m=l+r>>1;
        if(chk(m)) r=m;
        else l=m;
    }
    if(chk(l)) r=l;
    cout << r;
    return 0;
}