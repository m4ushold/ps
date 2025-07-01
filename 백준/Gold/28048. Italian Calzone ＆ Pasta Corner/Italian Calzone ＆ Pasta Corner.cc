#include <bits/stdc++.h>
using namespace std;

int N, M, A[101][101], B[10101];
vector<pair<int,int>> dir({
    {1,0}, {0,1}, {0,-1}, {-1,0}
});

bool chk(int x, int y) {
    return 1<=min(x,y) && x<=N && y<=M;
}

int solve(int x, int y) {
    int mx = A[x][y];
    memset(B, 0, sizeof(B));

    priority_queue<array<int,3>,vector<array<int,3>>,greater<>> pq;
    pq.push({mx,x,y});
    int cnt=0;
    while(pq.size()) {
        auto [c,x,y] = pq.top(); pq.pop();
        if(B[A[x][y]]) continue;
        B[A[x][y]]=1;
        mx = max(c, mx);
        cnt++;
        for(auto [dx,dy]:dir) if(chk(x+dx,y+dy) && mx < A[x+dx][y+dy]) {
            pq.push({A[x+dx][y+dy], x+dx, y+dy});
        } 
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    vector<pair<int,int>> src;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        int tot=0, cnt=0;
        for(auto [di,dj]:dir) if(chk(i+di,j+dj)) {
            tot++;
            if(A[i][j] < A[i+di][j+dj]) cnt++;
        }
        if(tot == cnt) src.push_back({i,j});
    }
    int ans=0;
    for(auto [x,y]:src) {
        ans = max(ans, solve(x,y));
    }
    cout << ans;
    return 0;
}