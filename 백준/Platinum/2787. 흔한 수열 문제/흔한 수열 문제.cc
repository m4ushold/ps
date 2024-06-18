#include <bits/stdc++.h>
using namespace std;

const int MAX_V=202;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], G[MAX_V][MAX_V], MX[MAX_V], MN[MAX_V];

bool dfs(int v) {
    vi[v]=1;
    for(int i=1;i<=N;i++) if(G[v][i]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int matching() {
    int cnt=0;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<MAX_V;j++) vi[j]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) G[i][j]=1;
        A[i]=B[i]=-1, MN[i]=1, MX[i]=N;
    }

    for(int t=0;t<M;t++) {
        int a,x,y,v; cin >> a >> x >> y >> v;
        for(int i=1;i<=N;i++) if(i<x || y<i) G[i][v]=0;
        
        for(int i=x;i<=y;i++) {
            if(a==1) MX[i]=min(MX[i], v);
            else MN[i]=max(MN[i], v);
        }
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(j<MN[i] || MX[i]<j) G[i][j]=0;

    if(matching() < N) cout << -1;
    else for(int i=1;i<=N;i++) cout << A[i] << ' ';
    return 0;
}