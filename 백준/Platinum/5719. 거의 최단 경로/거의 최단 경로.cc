#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N, M, vi[505], D[505], G[505][505], R[505][505], S, T;

void dijkstra() {
    for(int i=0;i<N;i++) D[i]=1e9, vi[i]=0;
    priority_queue<pii,vector<pii>, greater<>> pq;
    D[S]=0; pq.emplace(0,S);
    while(!pq.empty()) {
        auto [c,v] = pq.top(); pq.pop();
        if(vi[v]) continue; vi[v]=1;
        for(int i=0;i<N;i++) if(G[v][i]) {
            int w=G[v][i];
            if(D[i]>D[v]+w){
                D[i]=D[v]+w;
                pq.emplace(D[i], i);
            }
        }
    }
}

void remove() {
    queue<int> q; q.push(T);
    while(q.size()) {
        int v=q.front(); q.pop();
        for(int i=0;i<N;i++) if(R[v][i]) {
            int w=R[v][i];
            if(D[v]-w==D[i]) q.push(i), G[i][v]=R[v][i]=0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a=1;
    while(cin >> N >> M && N && M && cin >> S >> T) {
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) G[i][j]=0, R[i][j]=0;

        for(int i=0,s,e,w;i<M;i++) cin >> s >> e >> w, G[s][e]=R[e][s]=w;

        dijkstra();
        remove();
        dijkstra();
        cout << (D[T]==(int)1e9 ? -1 : D[T]) << '\n';
    }
    

    return 0;
}