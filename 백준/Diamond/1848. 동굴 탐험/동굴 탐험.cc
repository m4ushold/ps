#include <bits/stdc++.h>
using namespace std;
using PQ=priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>;

int N, M, vi[5050], D[5050], W[5050][5050], A[5050];
vector<pair<int,int>> G[5050];

void dijkstra(PQ &pq)
{
    while(!pq.empty()) {
        auto [c,v] = pq.top(); pq.pop();
        if(vi[v]) continue; vi[v]=1;
        for(auto [i,w]:G[v]) {
            if(D[i]>D[v]+w){
                D[i]=D[v]+w;
                pq.emplace(D[i], i);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vector<int> s;
    for(int i=0,a,b,c,d;i<M;i++) {
        cin >> a >> b >> c >> d;
        W[a][b]=c, W[b][a]=d;
        if(a>1 && b>1) G[a].push_back({b,c}), G[b].push_back({a,d});
        else s.push_back(max(a,b));
    }
    
    int dap=1e9;
    for(int i=0;i<13;i++) {
        for(int i=1;i<=N;i++) D[i]=1e9, vi[i]=0;
        PQ pq;
        for(int v:s) if(v>>i&1) pq.emplace(W[1][v], v), D[v]=W[1][v];
        dijkstra(pq);
        for(int v:s) if(~v>>i&1) dap=min(dap, W[v][1]+D[v]);

        pq=PQ();
        for(int i=1;i<=N;i++) D[i]=1e9, vi[i]=0;
        for(int v:s) if(~v>>i&1) pq.emplace(W[1][v], v), D[v]=W[1][v];
        dijkstra(pq);
        for(int v:s) if(v>>i&1) dap=min(dap, W[v][1]+D[v]);
    }

    cout << dap;

    return 0;
}