#include <bits/stdc++.h>
using namespace std;

int N, DP[10101][2];
vector<int> G[10101];

void dfs(int v=1, int p=-1) {
    for(int i:G[v]) if(p!=i) {
        dfs(i,v);
        DP[v][1]+=DP[i][0];
        DP[v][0]+=max(DP[i][1], DP[i][0]);
    }
}

void bt(vector<int> &vec, int v=1, int u=1, int p=-1) {
    if(u &&DP[v][1]>DP[v][0]) vec.push_back(v), u=0;
    else u=1;
    for(int i:G[v]) if(i!=p) bt(vec,i,u,v);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> DP[i][1];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs();
    cout << max(DP[1][1],DP[1][0]) << '\n';
    vector<int> v;
    bt(v);
    sort(v.begin(),v.end());
    for(int i:v) cout << i << ' ';
    return 0;
}