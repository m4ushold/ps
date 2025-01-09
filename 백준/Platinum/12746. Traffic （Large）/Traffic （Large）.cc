#include <bits/stdc++.h>
using namespace std;

const int sz=1<<18;
int N, Q, D[sz], P[22][sz], A[sz];
vector<int> G[sz];
void dfs(int v, int b=-1) { for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v); }
void dfs2(int v=1, int p=-1) {
    for(int i:G[v]) if(i!=p) dfs2(i,v), A[v]+=A[i];
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
void build() {
    dfs(1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    build();
    for(int i=1,u,v,l;i<=Q;i++) {
        cin >> u >> v, l=lca(u,v);
        A[u]+=1, A[v]+=1, A[l]-=2;
    }
    dfs2();
    int mx=0, u, v;
    for(int i=1;i<=N;i++) if(mx < A[i] || (mx==A[i] && min(i,P[0][i]) < u)) {
        mx=A[i], u=min(i,P[0][i]), v=max(i,P[0][i]);
    }
    cout << u << ' ' << v << ' ' << mx;
    return 0;
}