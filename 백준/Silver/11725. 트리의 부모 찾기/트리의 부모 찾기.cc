#include <bits/stdc++.h>
using namespace std;

int P[101010];
vector<int> G[101010];

void dfs(int v=1,int p=-1) {
    for(int i:G[v]) if(i!=p) P[i]=v, dfs(i,v);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1,s,e;i<n;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    dfs();
    for(int i=2;i<=n;i++) cout << P[i] << '\n';
    return 0;
}