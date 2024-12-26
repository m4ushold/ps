#include <bits/stdc++.h>
using namespace std;

const int MAX_V=3030;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], P[MAX_V];
vector<int> G[MAX_V];
char C[55][55];

void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[v]=u, true); }

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

int idx(int i, int j) {return (i-1)*M+j-1;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    init(N*M);

    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> C[i][j];
    for(int i=1;i<=N;i++) for(int j=1;j<M;j++) {
        if(isupper(C[i][j]) && isupper(C[i][j+1])) {
            Union(idx(i,j), idx(i,j+1));
        }
    }
    vector<pair<int,int>> dir({{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}});
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(C[i][j]=='x') {
        for(auto [dx,dy]:dir) if(isupper(C[i+dx][j+dy])) {
            G[idx(i,j)].push_back(Find(idx(i+dx,j+dy)));
        }
    }
    matching();
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(C[i][j]=='x') {
        int k = A[idx(i,j)];
        cout << i << ' ' << j << " ";
        int x=k/M+1, y=k%M+1;
        while(isupper(C[x][y])) cout << C[x][y++];
        cout << '\n';
    }
    

    
    return 0;
}