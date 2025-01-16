#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1<<13;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];
char C[55][55];

bool dfs(int v)  {
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int matching() {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=0;i<MAX_V;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int idx(int x, int y) {
    return (x-1)*M+y-1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> C[i][j];
    vector<pair<int,int>> dir({{1,0},{0,1},{-1,0},{0,-1}});
    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(C[i][j]=='.') {
        cnt++;
        for(auto [dx,dy]:dir) if(1<=min(i+dx,j+dy) && i+dx<=N && j+dy<=M && C[i+dx][j+dy]=='.') {
            int u=idx(i,j), v=idx(i+dx,j+dy);
            G[u].push_back(v), G[v].push_back(u);
        }
    }
    cout << cnt-matching()/2;
    return 0;
}