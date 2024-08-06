#include <bits/stdc++.h>
using namespace std;

int N, M, vi[101010], D[101010];
vector<pair<int,int>> G[101010];

void dijkstra(int s) {
    for(int i=1;i<=N;i++) D[i]=1e9, vi[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
    D[s]=0; pq.emplace(0,s);
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
    for(int i=0,s,e,w;i<M;i++) {
        cin >> s >> e;
        G[s].emplace_back(e,1);
        G[e].emplace_back(s,1);
    }
    dijkstra(1);
    cout << D[N]-1;
    return 0;
}