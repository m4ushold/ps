#include <bits/stdc++.h>
using namespace std;

const int MAX_V=2525;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], D[55][55], E[55][55];
char C[55][55];
vector<int> G[MAX_V];

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
    for(int i=1;i<=N*M;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> C[i][j];
    int id=0;
    for(int j=1;j<=M;j++) {
        for(int i=1;i<=N;i++) {
            if(C[i][j] == '*') {
                if(i==1 || C[i-1][j]=='.') ++id;
                D[i][j]=id;
            }
        }
    }
    id=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(C[i][j] == '*') {
                if(j==1 || C[i][j-1]=='.') ++id;
                if(D[i][j]) G[D[i][j]].push_back(id);
                E[i][j]=id;
            }
        }
    }

    cout << matching();
    return 0;
}