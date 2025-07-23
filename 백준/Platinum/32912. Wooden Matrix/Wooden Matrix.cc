#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, D[1010], P[22][1010], A[1010][1010], W[1010];
vector<pair<int,int>> G[1010];
void dfs(int v, int b=-1) { for(auto [i,w]:G[v]) if(i!=b) D[i]=D[v]+1, W[i]=W[v]+w, P[0][i]=v, dfs(i,v); }

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
    return W[u]+W[v]-W[l]-W[l];
}
void build() {
    dfs(1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

int PP[1010], S[1010];
void init(int n) { for(int i=1;i<=n;i++) PP[i]=i,S[i]=1; }
int Find(int v) { return PP[v]==v?v:PP[v]=Find(PP[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), PP[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<array<ll,3>> ed;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> A[i][j];
        if(i<j) ed.push_back({A[i][j],i,j});
    }
    sort(ed.begin(),ed.end());
    init(N);
    for(auto [w,u,v]:ed) {
        if(Union(u,v)) G[u].push_back({v,w}), G[v].push_back({u,w});
    }
    build();

    for(int i=1;i<=N;i++) for(int j=i+1;j<=N;j++) {
        if(A[i][j] != dst(i,j)) return cout << "No", 0;
    }
    cout << "Yes";
    return 0;
}