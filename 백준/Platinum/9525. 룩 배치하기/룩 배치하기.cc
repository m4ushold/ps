#include <bits/stdc++.h>
using namespace std;

const int MAX_V=10101;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], C[101][101], D[101][101];
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
    for(int i=0;i<MAX_V;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

void setId() {
    int pv=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(C[i][j]) continue;
        ++pv;
        int x=i, y=j;
        while(!C[x][y] && 1<=min(x,y) && max(x,y)<=N) C[x][y]=pv, x++;
    }

    pv=0;
    for(int j=1;j<=N;j++) for(int i=1;i<=N;i++) {
        if(D[i][j]) continue;
        ++pv;
        int x=i, y=j;
        while(!D[x][y] && 1<=min(x,y) && max(x,y)<=N) D[x][y]=pv, y++;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            char c; cin >> c;
            if(c=='X') C[i][j]=D[i][j]=-1;
        }
    }
    setId();
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(C[i][j]>0 && D[i][j]>0) {
        G[C[i][j]].push_back(D[i][j]);
    }

    cout << matching();

    return 0;
}