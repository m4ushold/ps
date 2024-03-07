#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N, M, vi[10101], D[10101], S;
vector<pii> G[10101];

void dijkstra()
{
    for(int i=1;i<=N;i++) D[i]=1e9, vi[i]=0;
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
    int t; cin >> t;
    while(t--) {
        for(int i=1;i<=N;i++) G[i].clear();
        cin >> N >> M >> S;
        for(int i=0,s,e,w;i<M;i++) {
            cin >> s >> e >> w;
            G[e].emplace_back(s,w);
        }
        dijkstra();
        int mx=0, cnt=0;
        for(int i=1;i<=N;i++) if(D[i]!=(int)1e9) mx=max(mx,D[i]), ++cnt;
        cout << cnt << ' ' << mx << '\n';
    }
    return 0;
}