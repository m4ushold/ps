#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, K, vi[10101][22], D[10101][22], S=1, T;
vector<pair<ll,ll>> G[10101];

void dijkstra()
{
    memset(D, 1e9, sizeof D);
    for(int i=1;i<=N;i++) for(int j=0;j<=K;j++) D[i][j]=LONG_LONG_MAX/2;
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>, greater<>> pq;
    D[S][0]=0; pq.emplace(0,S,0);
    while(!pq.empty()) {
        auto [c,v,k] = pq.top(); pq.pop();
        if(vi[v][k]) continue; vi[v][k]=1;
        for(auto [i,w]:G[v]) {
            if(D[i][k]>D[v][k]+w){
                D[i][k]=D[v][k]+w;
                pq.emplace(D[i][k], i, k);
            }
            if(k<K && D[i][k+1]>D[v][k]) {
                D[i][k+1]=D[v][k];
                pq.emplace(D[i][k+1], i, k+1);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0,s,e,w;i<M;i++) {
        cin >> s >> e >> w;
        G[s].emplace_back(e,w);
        G[e].emplace_back(s,w);
    }
    dijkstra();
    ll dap=LONG_LONG_MAX;
    for(int i=0;i<=K;i++) dap=min(dap, D[N][i]);
    cout << dap;
    return 0;
}