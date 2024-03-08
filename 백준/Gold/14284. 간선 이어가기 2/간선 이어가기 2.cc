#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N, M, vi[20202], D[20202], S=1, T;
vector<pii> G[20202];

void dijkstra()
{
    for(int i=1;i<=N;i++) D[i]=1e9;
    priority_queue<pii,vector<pii>, greater<>> pq;
    D[S]=0; pq.emplace(0,S);
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
        cin >> s >> e >> w;
        G[s].emplace_back(e,w);
        G[e].emplace_back(s,w);
    }
    cin >> S >> T;
    dijkstra();
    cout << D[T];

    return 0;
}