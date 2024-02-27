#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, D[101010], P[22][101010], A[22][101010];
vector<pair<ll,ll>> G[101010];

void dfs(int v, int p=-1) { for(auto [i,w]:G[v]) if(i!=p) D[i]=D[v]+1, P[0][i]=v, A[0][i]=w, dfs(i,v); }

pair<ll,ll> lca(int u, int v)
{
    ll diff, w=0;
    if(D[u]<D[v]) swap(u,v);
    diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) w+=A[i][u], u=P[i][u];
    if(u==v) return {u,w};
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) w+=A[i][u]+A[i][v], u=P[i][u], v=P[i][v];
    w+=A[0][u]+A[0][v];
    return {P[0][u], w};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1,a,b,c;i<N;i++) cin >> a >> b >> c, G[a].push_back({b,c}), G[b].push_back({a,c});
    dfs(1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) A[i][j]=A[i-1][j]+A[i-1][P[i-1][j]];

    for(int i=0,u,v,k;i<Q;i++) cin >> u >> v, cout << lca(u,v).second << "\n";
    return 0;
}