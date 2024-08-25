#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int N, M, U[101010], S[101010], P[101010], C[101010], ST[22][101010], D[101010];
vector<int> G[101010];
multiset<int> CS[101010];

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=ST[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(ST[i][u]!=ST[i][v]) u=ST[i][u], v=ST[i][v];
    return ST[0][u];
}

int dst(int u, int v) {
    int l=lca(u,v);
    return D[u]+D[v]-D[l]-D[l];
}

void buildSparseTable() {
    function<void(int,int)> df = [&](int v, int p) {
        for(int i:G[v]) if(i!=p) D[i]=D[v]+1, ST[0][i]=v, df(i,v);
    };
    df(1,-1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) ST[i][j]=ST[i-1][ST[i-1][j]];
}

int dfs(int v, int p=-1) {
    S[v]=1;
    for(int i:G[v]) if(i!=p && !U[i]) S[v]+=dfs(i,v);
    return S[v];
}

int getCentroid(int v, int sz, int p=-1) {
    for(int i:G[v]) if(i!=p && !U[i] && S[i]*2>sz) return getCentroid(i,sz,v);
    return v;
}

void build(int v=1, int p=-1) {
    v = getCentroid(v, dfs(v));
    U[v]=1, P[v]=p;
    for(int i:G[v]) if(!U[i]) build(i, v);
}

void update(int v) {
    C[v]^=1;
    for(int i=v;i!=-1;i=P[i]) {
        if(C[v]) CS[i].insert(dst(i,v));
        else CS[i].erase(CS[i].find(dst(i,v)));
    }
}

int qry(int v) {
    int res=INF;
    for(int i=v;i!=-1;i=P[i]) {
        if(CS[i].size()) res = min(res, *CS[i].begin() + dst(i,v));
    }
    return res == INF ? -1 : res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie();
    cin >> N;
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    build();
    buildSparseTable();

    cin >> M;
    for(int i=0,a,b;i<M;i++) {
        cin >> a >> b;
        if(a==1) update(b);
        else cout << qry(b) << '\n';
    }
    return 0;
}