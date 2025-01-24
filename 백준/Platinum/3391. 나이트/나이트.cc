#include <bits/stdc++.h>
using namespace std;

const int sz=1<<15;
int N, M, A[sz], B[sz], vi[sz], C[202][202], b, w;
vector<int> G[sz];

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
    int cnt=0, n=max(b,w);
    for(int i=1;i<=n;i++) A[i]=B[i]=-1;
    for(int i=1;i<=n;i++) {
        for(int i=0;i<=n;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) C[i][j]=i+j&1 ? ++b : ++w;
    for(int i=0,s,e;i<M;i++) cin >> s >> e, C[s][e]=0;
    
    vector<pair<int,int>> dir({{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}});
    for(int x=1;x<=N;x++) for(int y=1;y<=N;y++) if(C[x][y] && (x+y&1)) {
        for(auto [dx,dy]:dir) if(0<min(x+dx,y+dy) && max(x+dx,y+dy)<=N && C[x+dx][y+dy]) {
            int u=C[x][y], v=C[x+dx][y+dy];
            G[u].push_back(v);
        }
    }
    cout << N*N-M-matching();
    return 0;
}