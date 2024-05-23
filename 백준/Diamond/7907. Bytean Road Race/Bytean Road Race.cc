#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

int N, M, K, C[101010], RA[101010], RB[101010];
Point P[101010];
vector<int> G[101010], A, B;

void dfs(int v, int f) {
    C[v]=1;
    for(int i:G[v]) if(!C[i]) dfs(i,f);
    (f ? A : B).push_back(v);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> P[i].first >> P[i].second;
    for(int i=1,s,e;i<=M;i++) {
        cin >> s >> e;
        if(P[s].first == P[e].first && P[s].second < P[e].second) swap(s,e);
        else if(P[s].first != P[e].first && P[s].first > P[e].first) swap(s,e);
        G[s].push_back(e);
    }
    for(int i=1;i<=N;i++) if(G[i].size()>1) {
        if(P[G[i][0]]>P[G[i][1]]) swap(G[i][0], G[i][1]);
    }
    for(int i=1;i<=N;i++) if(!C[i]) dfs(i,1);
    for(int i=1;i<=N;i++) reverse(G[i].begin(),G[i].end());
    memset(C,0,sizeof C);
    for(int i=1;i<=N;i++) if(!C[i]) dfs(i,0);

    reverse(A.begin(),A.end()), reverse(B.begin(),B.end());
    for(int i=0;i<N;i++) RA[A[i]]=i+1, RB[B[i]]=i+1;

    while(K--) {
        int u, v; cin >> u >> v;
        if((RA[u] > RA[v] && RB[u] > RB[v]) || (RA[u] < RA[v] && RB[u] < RB[v])) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}