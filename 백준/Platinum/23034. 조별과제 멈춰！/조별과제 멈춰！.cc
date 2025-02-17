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

const int sz=1010;
int N, M, Q, P[sz], D[sz], W[sz], Par[sz];
vector<pair<int,int>> G[sz];

void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[u]=v, true); }
void dfs(int v=1, int p=-1) {for(auto [i,w]:G[v]) if(i!=p) W[i]=w, D[i]=D[v]+1, Par[i]=v, dfs(i,v);}

int qry(int u, int v) {
    int mx=0;
    while(u!=v) {
        if(D[u] < D[v]) swap(u,v);
        mx = max(mx,W[u]);
        u = Par[u];
    }
    return mx;
}

void sol(int tc) {
    cin >> N >> M;
    vector<array<int,3>> edge(M);
    for(auto &[w,u,v]:edge) cin >> u >> v >> w;
    sort(all(edge));
    init(N);
    ll mst = 0;
    for(auto [w,u,v]:edge) if(Union(u,v)) mst+=w, G[u].push_back({v,w}), G[v].push_back({u,w});
    dfs();
    cin >> Q;
    while(Q--) {
        int u,v; cin >> u >> v;
        cout << mst-qry(u,v) << '\n';
    }
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}