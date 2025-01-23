#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, T, K, D[1<<17], P[19][1<<17];
vector<int> G[1<<17];
int idx(int x, int y) {return x*M+y;}

void dfs(int v, int b=-1) { for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v); }

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
    return D[u]+D[v]-D[l]-D[l];
}
void build() {
    dfs(0);
    for(int i=1;i<19;i++) for(int j=0;j<N*M;j++) P[i][j]=P[i-1][P[i-1][j]];
}
void addEdge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> T;
    for(int i=0;i<N-1;i++) for(int j=0,a;j<M;j++) {
        cin >> a;
        if(!a) addEdge(idx(i,j),idx(i+1,j));
    }
    for(int i=0;i<N;i++) for(int j=0,a;j<M-1;j++) {
        cin >> a;
        if(!a) addEdge(idx(i,j),idx(i,j+1));
    }
    build();

    vector<array<ll,4>> vec;
    cin >> K;
    for(int i=1,s,e,a,b,c,d,v;i<=K;i++) {
        cin >> s >> e >> a >> b >> c >> d >> v;
        vec.push_back({s,idx(a,b),idx(c,d),v});
        vec.push_back({e+1,idx(a,b),idx(c,d),-v});
    }

    sort(vec.begin(),vec.end(),greater<>());

    ll dap=0;
    for(int t=1;t<=T;t++) {
        while(vec.size() && vec.back()[0]<=t) {
            auto [i,u,v,x]=vec.back();
            dap+=(dst(u,v)+1)*x;
            vec.pop_back();
        }
        cout << dap << '\n';
    }

    return 0;
}