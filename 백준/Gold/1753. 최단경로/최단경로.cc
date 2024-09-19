#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N, M, vi[20202], D[20202], S;
vector<pair<int,int>> G[20202];

void dijkstra()
{
    for(int i=1;i<=N;i++) D[i]=1e9;
    priority_queue<pii,vector<pii>, greater<>> pq;
    D[S]=0; pq.emplace(0,S);
    while(!pq.empty()) {
        auto [c,v] = pq.top(); pq.pop();
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
    cin >> N >> M >> S;
    for(int i=0,u,v,w;i<M;i++) {
        cin >> u >> v >> w;
        G[u].emplace_back(v,w);
    }
    dijkstra();
    for(int i=1;i<=N;i++) {
        if (D[i]==1e9) cout << "INF\n";
        else cout << D[i] << '\n';
    }

    return 0;
}