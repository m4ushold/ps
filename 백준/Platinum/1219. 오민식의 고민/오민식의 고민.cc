#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, S, T;
vector<tuple<ll,ll,ll>> E;
ll D[55], C[55], V[55], INF=LONG_LONG_MAX/4;
vector<int> G[55], R[55];

bool bellmanFord() {
    fill(D,D+55,INF);
    D[S]=min(0LL,-C[S]);
    for(int i=1,f;i<=N;i++) {
        f=0;
        for(auto [s,e,w]:E) {
            if(D[s]==INF) continue;
            if(D[e]>D[s]+w) {
                D[e]=D[s]+w;
                if(V[e]) f=true;
            }
        }
        if(i==N&&f) return false;
    }
    return true;
}

void dfs(int v=T) {
    if(V[v]) return;
    V[v]=1;
    for(int i:R[v]) if(!V[i]) dfs(i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S >> T >> M;
    E.resize(M);
    for(auto &[s,e,w]:E) cin >> s >> e >> w, R[e].push_back(s);
    for(int i=0;i<N;i++) cin >> C[i];
    for(auto &[s,e,w]:E) w=w-C[e];

    dfs();
    int f=bellmanFord();
    if(D[T]==INF) cout << "gg";
    else if(f) cout << -D[T];
    else cout << "Gee";
    return 0;
}