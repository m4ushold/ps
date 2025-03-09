#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());

using namespace std;
using ll = long long;
using lf = double;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

// rope
#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension

const int sz=303030;
int N, M, Q, A[505], P[sz], S[sz], PP[22][sz], D[sz];
lf C[sz], WW[22][sz];
vector<pair<int,lf>> G[sz];

void dfs(int v=1, int b=-1) {
    for(auto [i,w]:G[v]) if(i!=b) D[i]=D[v]+1, WW[0][i]=w, PP[0][i]=v, dfs(i,v);
}
lf w_min(int u, int v) {
    lf res=numeric_limits<lf>::infinity();
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) res = min(res, WW[i][u]), u=PP[i][u];
    if(u==v) return res;
    for(int i=21;i>=0;i--) if(PP[i][u]!=PP[i][v]) res = min({res,WW[i][u],WW[i][v]}), u=PP[i][u], v=PP[i][v];
    return min(res,WW[0][u]);
}

void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
int idx(int x, int y){ return (x-1)*N + y; }

void sol(int tc) {
    cin >> N;
    vector<pair<int,int>> v(N);
    for(auto &[x,y]:v) cin >> x >> y;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) C[idx(i,j)] = hypot(v[i-1].first - v[j-1].first, v[i-1].second - v[j-1].second);

    cin >> M;
    for(int i=0,u,v;i<M;i++) cin >> u >> v, G[u].push_back({v,0}), G[v].push_back({u,0});
    vector<tuple<lf,int,int>> edge;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        for(auto [k,w]:G[i]) edge.push_back({min(C[idx(i,j)], C[idx(k,j)]), idx(i,j), idx(k,j)});
        for(auto [k,w]:G[j]) edge.push_back({min(C[idx(i,j)], C[idx(i,k)]), idx(i,j), idx(i,k)});
    }
    for(int i=1;i<=N*N;i++) G[i].clear();
    sort(all(edge),greater<>()), init(N*N);
    for(auto [w,u,v]:edge) if(Union(u,v)) G[u].push_back({v,w}), G[v].push_back({u,w});

    dfs();
    for(int i=1;i<22;i++) for(int j=1;j<=N*N;j++) PP[i][j] = PP[i-1][PP[i-1][j]], WW[i][j] = min(WW[i-1][j], WW[i-1][PP[i-1][j]]);
    
    cin >> Q;
    for(int i=1,s,e;i<=Q;i++) {
        cin >> s >> e;
        cout << fixed << setprecision(12) << w_min(idx(s,e),idx(e,s)) << '\n';
    }
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}