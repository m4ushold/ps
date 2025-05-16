#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
ll N, D[sz];
vector<pair<int,int>> G[sz];

void dfs(int v=1, int p=-1) {
    for(auto [i,w]:G[v]) if(i!=p) {
        D[i]=D[v]+w;
        dfs(i,v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1,u,v,w;i<N;i++) {
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    ll a, b, mx=0;
    dfs();
    for(int i=1;i<=N;i++) {
        if(mx<D[i]) mx=D[i], a=i;
    }
    D[a]=0, mx=0;
    dfs(a);
    for(int i=1;i<=N;i++) {
        if(mx<D[i]) mx=D[i], b=i;
    }

    ll ans=0;
    for(int i=1;i<=N;i++) if(i!=b) ans=max(ans, D[i]);
    D[b]=0;
    dfs(b);
    for(int i=1;i<=N;i++) if(i!=a) ans=max(ans, D[i]);
    cout << ans;  
    return 0;
}