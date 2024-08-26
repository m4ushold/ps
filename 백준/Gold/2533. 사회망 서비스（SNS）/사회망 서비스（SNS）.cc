#include <bits/stdc++.h>
using namespace std;

int N, DP[2][1010101];
vector<int> G[1010101];

void dfs(int v, int p=-1) {
    DP[0][v]=0, DP[1][v]=1;
    for(int i:G[v]) if(i!=p) {
        dfs(i,v);
        DP[0][v]+=DP[1][i];
        DP[1][v]+=min(DP[0][i], DP[1][i]);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);

    cout << min(DP[0][1], DP[1][1]);
    return 0;
}