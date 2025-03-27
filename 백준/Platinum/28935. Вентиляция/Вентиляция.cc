#include <bits/stdc++.h>
using namespace std;

const int sz=1<<18;
int N, D[sz], P[22][sz];
vector<int> G[sz];
void dfs(int v, int b=-1) { for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v); }

int up(int u, int d) {
    for(int i=0;d;i++,d>>=1) if(d&1) u=P[i][u];
    return u;
}

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}
int dst(int u, int v) {
    int l=lca(u,v);
    return D[u]+D[v]-D[l]-D[l];
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
    cin >> N;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, addEdge(u,v);
    build();
    int q; cin >> q;
    for(int i=1,u,v;i<=q;i++) {
        cin >> u >> v;
        int l = lca(u,v), d = dst(u,v);
        if(l == u) {
            cout << up(v,d-1) << '\n';
        } else cout << P[0][u] << '\n';
    }
    return 0;
}