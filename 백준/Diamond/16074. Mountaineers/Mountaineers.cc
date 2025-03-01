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

int N, H, W, Q, F[505][505], P[303030], S[303030], PP[22][303030], WW[22][303030], D[303030];
vector<pair<int,int>> G[303030];

void dfs(int v=1, int b=-1) { for(auto [i,w]:G[v]) if(i!=b) D[i]=D[v]+1, WW[0][i]=w, PP[0][i]=v, dfs(i,v); }
int w_max(int u, int v) {
    int res=-1;
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) res = max(res, WW[i][u]), u=PP[i][u];
    if(u==v) return res;
    for(int i=21;i>=0;i--) if(PP[i][u]!=PP[i][v]) res = max({res,WW[i][u],WW[i][v]}), u=PP[i][u], v=PP[i][v];
    return max(res,WW[0][u]);
}

void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
int idx(int i, int j) {return (i-1)*W+j;}

void sol(int tc) {
    cin >> H >> W >> Q;
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) cin >> F[i][j];
    init(N = H * W);
    
    vector<array<int,3>> edge;
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) {
        if(i<H) edge.push_back({max(F[i][j],F[i+1][j]),idx(i,j),idx(i+1,j)});
        if(j<W) edge.push_back({max(F[i][j],F[i][j+1]),idx(i,j),idx(i,j+1)});
    }
    sort(edge.begin(),edge.end());
    for(auto [w,u,v]:edge) if(Union(u,v)) {
        G[u].push_back({v,w}), G[v].push_back({u,w});
    }
    dfs();
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) PP[i][j] = PP[i-1][PP[i-1][j]], WW[i][j] = max(WW[i-1][j], WW[i-1][PP[i-1][j]]);

    for(int i=1,a,b,y,c,d,z;i<=Q;i++) {
        cin >> a >> b >> c >> d;
        cout << max({F[a][b],F[c][d],w_max(idx(a,b),idx(c,d))}) << '\n';
    }
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}