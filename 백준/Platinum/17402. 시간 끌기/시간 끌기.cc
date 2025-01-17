#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1<<17;
int N, M, K, A[MAX_V], B[MAX_V], vi[MAX_V], C[202][202];
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
    for(int i=1;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for(int i=1,u,v;i<=K;i++) cin >> u >> v, G[u].push_back(v);
    cout << N+M-matching();
    return 0;
}