#include <bits/stdc++.h>
using namespace std;

const int MAX_V=101;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

bool dfs(int v) 
{
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
    for(int i=0;i<N*M;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int f(int x, int y) {
    return x*M+y;
}

bool bound(int x, int y) {
    return 0<=min(x,y) && x<N && y<M;
}

char C[11][11];

void sol() {
    cin >> N >> M;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    vector<pair<int,int>> v({{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,1}});
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        cin >> C[i][j];
        G[f(i,j)].clear();
    }
    int x=0;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(C[i][j]=='.') {
        x++;
        for(auto [x,y]:v) if(bound(i+x,j+y) && C[i+x][j+y]=='.') {
            G[f(i,j)].push_back(f(i+x,j+y));
        }
    }
    x=N*M-x;

    int mf=matching(), cnt=0;
    for(int i=0;i<N*M;i++) if(B[i]==-1) cnt++;
    cout << mf/2+cnt-x << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}