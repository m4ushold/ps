#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, R, D[101010], VI[101010];
vector<int> G[101010];
ll A;

void dfs(int v) {
    static ll ord=0;
    if(VI[v]) return;
    VI[v]=1, A+=++ord*D[v];
    for(int i:G[v]) if(!VI[i]) D[i]=D[v]+1, dfs(i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R;
    for(int i=0,s,e;i<M;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    for(int i=1;i<=N;i++) sort(G[i].begin(),G[i].end(),greater<>());
    memset(D,-1,sizeof D), D[R]=0, dfs(R);
    cout << A;
    return 0;
}