#include <bits/stdc++.h>
using namespace std;

const int MAX_V=3333;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
char C[55][55];
vector<int> G[MAX_V];

bool dfs(int v) {
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
    for(int i=1;i<=N*N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

bool bound(int x, int y) {return 1<=min(x,y) && max(x,y)<=N;}

int idx(int x, int y) {return (x-1)*N+y;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    int tot=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> C[i][j];
        if(C[i][j]!='x') tot++;
    }
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;

    vector<pair<int,int>> dir({{1,0}, {0,1}, {-1,0}, {0,-1}});
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(C[i][j]=='o') {
        for(auto [dx,dy]:dir) if(bound(i+dx,j+dy) && C[i+dx][j+dy]=='.') {
            G[idx(i,j)].push_back(idx(i+dx,j+dy));
        }
    }

    cout << tot-matching();
    return 0;
}