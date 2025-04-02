#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17;
ll N, Q, D[sz], P[22][sz], S[sz];
vector<int> G[sz];
void dfs(int v, int b=-1) { for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v), S[v]+=S[i]; }

int up(int u, int diff) {
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    return u;
}
int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    u=up(u,D[u]-D[v]);
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}
void addEdge(int u, int v) {
    G[u].push_back(v), G[v].push_back(u);
}
void build() {
    dfs(1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> S[i];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, addEdge(u,v);
    build();

    for(int i=0,r,v;i<Q;i++) {
        cin >> r >> v;
        if(r == v) cout << S[1] << '\n';
        else if(lca(r,v) == v) {
            cout << S[1] - S[up(r, D[r] - D[v] - 1)] << '\n';
        } else cout << S[v] << '\n';
    }
    return 0;
}