#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> G[1010];
int D[1010];

void bfs(int s=1) {
    queue<pair<int,int>> q;
    q.push({s,0});
    vector<int> vi(1010);
    while(!q.empty()) {
        auto [v,i]=q.front(); q.pop();
        if(vi[v]) continue;
        vi[v]=1;
        D[v]=min(D[v],i);
        for(int j:G[v]) q.push({j,i+1});
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=0,s,e;i<m;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    for(int i=0;i<1010;i++) D[i]=1e9;
    int q; cin >> q;
    while(q--) {
        int s,e; cin >> s >> e;
        G[s].push_back(e), G[e].push_back(s);
        bfs();
        for(int i=1;i<=n;i++) cout << (D[i]==(int)1e9 ? -1 : D[i]) << ' ';
        cout << '\n';
    }
    return 0;
}