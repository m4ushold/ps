#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

constexpr int sz=5001;
int N, M, D[sz], C[sz], R[sz], B[sz][sz];
vector<int> G[sz];

void bfs(int v) {
    for(int i=1;i<=N;i++) B[v][i]=0;
    B[v][v]=1;
    queue<int> q;
    q.push(v);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i:G[u]) if(!B[v][i]) {
            B[v][i]=B[v][u]+1;
            q.push(i);
        }
    }
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> C[i] >> R[i];
    for(int i=1;i<=M;i++) {
        int u,v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }

    for(int i=1;i<=N;i++) bfs(i), D[i]=1e9;

    priority_queue<pii,vector<pii>,greater<>> pq;
    pq.emplace(0,1);
    D[1]=0;
    while(pq.size()) {
        auto [c,v] = pq.top(); pq.pop();
        if(c > D[v]) continue;
        for(int i=1;i<=N;i++) if(B[v][i] && B[v][i]-1 <= R[v]) {
            if(D[i] > D[v]+C[v]) {
                D[i]=D[v]+C[v];
                pq.emplace(D[i], i);
            }
        }
    }

    cout << D[N];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}