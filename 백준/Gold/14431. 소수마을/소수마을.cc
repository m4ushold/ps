#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[4040];
int N, vi[20202], S[20202]={1,1}, D[20202];

int dst(pair<int,int> a, pair<int,int> b) {
    int dx= a.first-b.first, dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

void dijkstra(int s=0) {
    for(int i=0;i<N;i++) D[i]=1e9, vi[i]=0;
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<10101;i++) if(!S[i]) for(int j=2*i;j<10101;j+=i) S[j]=1;

    int x1,y1,x2,y2,n; cin >> x1 >> y1 >> x2 >> y2 >> N;
    vector<pair<int,int>> v(N);
    for(auto &[x,y]:v) cin >> x >> y;
    v.insert(v.begin(),{x1,y1}), v.push_back({x2,y2});
    N+=2;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        int w=dst(v[i],v[j]);
        if(!S[w]) G[i].push_back({j,w}), G[j].push_back({i,w});
    }

    dijkstra();
    cout << (D[N-1] == (int)1e9 ? -1 : D[N-1]);
    return 0;
}