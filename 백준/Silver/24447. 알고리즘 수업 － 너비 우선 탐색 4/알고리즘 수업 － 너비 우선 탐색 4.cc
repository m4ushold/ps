#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, R, D[101010], VI[101010];
vector<int> G[101010];

ll bfs(int v) {
    queue<pair<int,int>> q;
    q.push({v,0}), VI[v]=1;
    ll t=1,ret=0;
    while(q.size()) {
        auto [u,d]=q.front(); q.pop();
        D[u]=d, ret+=d*t++;
        for(int i:G[u]) if(!VI[i]) q.push({i,d+1}), VI[i]=1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R;
    for(int i=0,s,e;i<M;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    for(int i=1;i<=N;i++) sort(G[i].begin(),G[i].end());
    memset(D,-1,sizeof D), D[R]=0;
    cout << bfs(R);
    return 0;
}