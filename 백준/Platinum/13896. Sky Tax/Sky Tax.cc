#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
int N, Q, R, D[sz], P[18][sz], DP[sz];
vector<int> G[sz];
void dfs(int v, int b=-1) {
    DP[v]=1;
    for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v), DP[v] += DP[i];
}
int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=17;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}
void build() {
    dfs(1);
    for(int i=1;i<18;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

void sol() {
    static int tc=0;
    memset(D, 0, sizeof(D));
    for(int i=1;i<sz;i++) G[i].clear();
    cout << "Case #" << ++tc << ":\n";

    cin >> N >> Q >> R;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    build();
    for(int i=1,op,u;i<=Q;i++) {
        cin >> op >> u;
        int l=lca(R,u);
        if(!op) R = u;
        else if(op && u == R) cout << N << '\n';
        else if(op && l != u) cout << DP[u] << '\n';
        else {
            int diff = D[R] - D[u] - 1, t = R;
            for(int i=0;diff;i++,diff>>=1) if(diff&1) t=P[i][t];
            cout << N-DP[t] << "\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}