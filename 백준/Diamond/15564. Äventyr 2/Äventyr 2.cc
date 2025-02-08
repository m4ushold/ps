#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int N, M, U[101010], S[101010], P[101010], C[101010], ST[18][101010], D[101010];
vector<int> G[101010];
multiset<int> CS[101010];

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=ST[i][u];
    if(u==v) return u;
    for(int i=17;i>=0;i--) if(ST[i][u]!=ST[i][v]) u=ST[i][u], v=ST[i][v];
    return ST[0][u];
}

int dst(int u, int v) {
    int l=lca(u,v);
    return D[u]+D[v]-D[l]-D[l];
}

void df(int v, int p) {
    for(int i:G[v]) if(i!=p) D[i]=D[v]+1, ST[0][i]=v, df(i,v);
};

void buildSparseTable() {
    df(1,-1);
    for(int i=1;i<18;i++) for(int j=1;j<=N;j++) ST[i][j]=ST[i-1][ST[i-1][j]];
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
    v = getCentroid(v, dfs(v,p));
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
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=2,u;i<=N;i++) cin >> u, G[u].push_back(i), G[i].push_back(u);
    build();
    buildSparseTable();

    for(int i=0,a,b,f=0;i<M;i++) {
        cin >> a >> b;
        if(a==1) update(b), f=1;
        else cout << (f?qry(b):-1) << '\n';
    }
    return 0;
}