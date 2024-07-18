#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, vi[303030];
vector<pair<ll,ll>> G[303030];

pair<ll,ll> f(int v, ll d)
{
    vi[v] = true;
    ll idx=v, res=d;
    for(auto [u,w]:G[v]) if (!vi[u]) {
        auto [i,j]=f(u,d+w);
        if(j>res) res=j, idx=i;
    }
    return {idx,res};
}

pair<ll,ll> f(int v) {
    memset(vi,0,sizeof vi);
    return f(v,0);
}

vector<int> dap;
int VI[303030];

void bfs(int v) {
    queue<int> q; q.push(v);
    while(q.size()) {
        int u=q.front(); q.pop();
        if(VI[u]) continue;
        VI[u]=1;
        dap.push_back(u);
        for(auto [t,w]:G[u]) q.push(t);
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,u,v,w;i<N;i++) cin >> u >> v, G[u].push_back({v,1}), G[v].push_back({u,1});
    auto [v,d]=f(f(1).first);
    if(d<=2) {cout << "NO"; return 0;}

    int u=G[v].front().first;
    for(int i=0;i<G[u].size();i++) {
        if(G[u][i].first==v) swap(G[u][i], G[u][0]);
    }

    bfs(u);

    cout << "YES\n";
    for(int i:dap) cout << i << ' ';
    return 0;
}