#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, D[202020][2], DP[101010][2];
vector<int> G[202020];

void dfs(int v=0, int p=-1) {
    D[v][0]=0, D[v][1]=1;
    for(int i:G[v]) if(i>=N && i!=p) {
        dfs(i, v);
        D[v][1]+=min(D[i][0], D[i][1]);
        D[v][0]+=D[i][1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0,u,v;i<N+M;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    for(int i=0;i<N;i++) dfs(i);
    ll ans=1e9;
    DP[0][0]=1e9, DP[0][1]=D[0][1];
    for(int i=1;i<N;i++) {
        DP[i][1] = min(DP[i-1][1], DP[i-1][0]) + D[i][1];
        DP[i][0] = DP[i-1][1] + D[i][0];
    }
    ans=min({ans, DP[N-1][0], DP[N-1][1]});
    DP[0][0]=D[0][0], DP[0][1]=1e9;
    for(int i=1;i<N;i++) {
        DP[i][1] = min(DP[i-1][1], DP[i-1][0]) + D[i][1];
        DP[i][0] = DP[i-1][1] + D[i][0];
    }
    ans=min(ans, DP[N-1][1]);
    cout << ans;
    return 0;
}