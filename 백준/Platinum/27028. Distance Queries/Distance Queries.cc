#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, Q, D[101010], P[19][101010], S[101010];
ll W[101010];
vector<pair<int,int>> G[101010];

void init(int n) {for(int i=1;i<=n;i++) S[i]=i;}
int Find(int v) {return S[v]==v?v:S[v]=Find(S[v]);}
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]=v, true);}
void dfs(int v, int b=-1) { for(auto [i,w]:G[v]) if(i!=b) D[i]=D[v]+1, W[i]=W[v]+w, P[0][i]=v, dfs(i,v); }

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=18;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

int dst(int u, int v) {
    int l=lca(u,v);
    return W[u]+W[v]-W[l]-W[l];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    init(N);
    vector<array<int,3>> v(M);
    for(auto &[w,s,e]:v) {
        char c; cin >> s >> e >> w >> c;
    }
    sort(v.begin(),v.end());
    for(auto [w,s,e]:v) {
        if(Union(s,e)) G[s].push_back({e,w}), G[e].push_back({s,w});
    }
    dfs(1);
    for(int i=1;i<19;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
    cin >> Q;
    for(int i=0,a,b;i<Q;i++) {
        cin >> a >> b;
        cout << dst(a,b) << '\n';
    }
    return 0;
}