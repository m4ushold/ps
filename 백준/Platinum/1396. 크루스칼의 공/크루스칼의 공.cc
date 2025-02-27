#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());

using namespace std;
using ll = long long;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

// rope
#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension

const int sz=1<<18;
int N, M, Q, D[sz], P[22][sz], PP[sz], T[sz], W[sz], V[sz];
vector<int> G[sz];

void dfs(int v, int b=-1) {
    V[v]=1;
    for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v), T[v]+=T[i];
}
int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

void init(int n) { for(int i=1;i<=n;i++) PP[i]=i; }
int Find(int v) { return PP[v]==v?v:PP[v]=Find(PP[v]); }
bool Union(int u, int v) { return (u=Find(u))!=(v=Find(v)) && (PP[u]=v, true); }

void sol(int tc) {
    cin >> N >> M;
    init(2*N-1);
    for(int i=1;i<=N;i++) T[i]=1;
    vector<array<int,3>> edge(M);
    for(auto &[w,u,v]:edge) cin >> u >> v >> w;
    sort(all(edge));

    int x = N + 1;
    for(auto [w,u,v]:edge) if(Find(u) != Find(v)) {
        u = Find(u), v = Find(v);
        G[x].push_back(u), G[x].push_back(v);
        W[x] = w;
        Union(u,x), Union(v,x), x++;
    }
    for(int i=2*N-1;i;i--) if(!V[i]) dfs(i);
    for(int i=1;i<22;i++) for(int j=1;j<=2*N-1;j++) P[i][j]=P[i-1][P[i-1][j]];
    
    cin >> Q;
    for(int i=0,u,v;i<Q;i++) {
        cin >> u >> v;
        if(Find(u)!=Find(v)) {cout << "-1\n"; continue;}
        int l = lca(u,v);
        cout << W[l] << ' ' << T[l] << '\n';
    }
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}