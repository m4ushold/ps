#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, Q, D[101010], P[22][101010];
vector<int> G[101010];

void dfs(int v, int b=-1) {
    for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v);
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
    return D[u]+D[v]-2*D[l];
}

void build() {
    dfs(1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

void sol(int tc) {
    cin >> N;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    build();
    cin >> Q;
    for(int i=1;i<=Q;i++) {
        int x,y,a,b,k; cin >> x >> y >> a >> b >> k;
        int d1 = dst(a,b), d2 = dst(a,x) + 1 + dst(y,b), d3 = dst(a,y) + 1 + dst(x,b);
        int f=0;
        if(d1<=k && (d1&1) == (k&1)) f=1;
        if(d2<=k && (d2&1) == (k&1)) f=1;
        if(d3<=k && (d3&1) == (k&1)) f=1;
        cout << (f?"YES":"NO") << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}