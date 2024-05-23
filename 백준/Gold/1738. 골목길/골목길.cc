#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<tuple<ll,ll,ll>> E;
ll D[101], P[101], F[101], V[101], INF=0x3f3f3f3f3f3f3f3f;
vector<int> G[101];

bool bf(int s=1) {
    fill(D,D+101,INF);
    D[s]=0;
    for(int i=1,f;i<=N;i++) {
        f=0;
        for(auto [s,e,w]:E) {
            if(D[s]==INF) continue;
            if(D[e]>D[s]+w) D[e]=D[s]+w, f=e, P[e]=s;
        }
        if(i==N && f && F[f]) return false;
    }
    return true;
}

void dfs(int v=1) {
    V[v]=1;
    if(v==N) F[v]=1;
    for(int i:G[v]) {
        if(!V[i]) dfs(i);
        F[v]|=F[i];
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,u,v,w;i<M;i++) cin >> u >> v >> w, E.emplace_back(u,v,-w), G[u].push_back(v);
    dfs();

    if(bf()) {
        vector<int> v;
        v.push_back(N);
        while(P[v.back()]) v.push_back(P[v.back()]);
        reverse(v.begin(),v.end());
        for(int i:v) cout << i << ' ';
        cout << '\n';
    } else cout << -1;
    return 0;
}