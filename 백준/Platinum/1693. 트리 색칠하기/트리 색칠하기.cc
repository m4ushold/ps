#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, DP[101010][22];
vector<int> G[101010];

ll dfs(int v, int c, int p=-1) {
    if(DP[v][c]) return DP[v][c];
    for(int i:G[v]) if(i!=p) {
        ll mn=LONG_LONG_MAX;
        for(int j=1;j<18;j++) if(j!=c) mn=min(mn,dfs(i,j,v));
        DP[v][c]+=mn;
    }
    return DP[v][c]+=c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1,u,v;i<n;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    ll mn=LONG_LONG_MAX;
    for(int i=1;i<18;i++) mn=min(mn,dfs(1,i));
    cout << mn;
    return 0;
}