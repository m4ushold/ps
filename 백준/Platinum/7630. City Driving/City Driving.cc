#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<int,int>;

int N, Q, D[101010], P[18][101010], W[101010];
vector<pll> G[101010];

void dfs(int v, int b=-1) {
    for(auto [i,w]:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, W[i]=W[v]+w, dfs(i,v);
}

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=17;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

void build() {
    dfs(0);
    for(int i=1;i<18;i++) for(int j=0;j<N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

int dst(int u, int v) {
    int l = lca(u,v);
    return W[u] + W[v] - W[l] * 2;
}

struct dsu {
    int n;
    vector<int> p;
    dsu(int n) : p(n,-1), n(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, true);
    }
};

void sol(int N) {
    dsu d(N);
    int uu, vv, ww;

    for(int i=1;i<=N;i++) {
        int u,v,w; cin >> u >> v >> w;
        if(d.same(u,v)) {
            uu = u, vv = v, ww = w;
            continue;
        }
        d.merge(u,v);

        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    build();

    cin >> Q;
    for(int i=1;i<=Q;i++) {
        int u,v; cin >> u >> v;
        cout << min({dst(u,v), dst(u,uu) + ww + dst(vv,v), dst(u,vv) + ww + dst(uu,v)}) << endl;
    }

    for(int i=0;i<N;i++) vector<pll>().swap(G[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while(cin >> N && N) sol(N);
    return 0;
}