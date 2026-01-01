#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<18;
int N, M, D[sz], P[22][sz], I[sz], C[sz];
ll W[sz];
vector<int> G[sz], T[sz];

void dfs(int v, int b=-1) {
    for(auto i:T[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v);
}

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

void build() {
    for(int i=1;i<=N;i++) if(C[i]) dfs(i);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
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

void d2(int v=1, int p=-1) {
    for(int i:T[v]) if(i!=p) {
        d2(i,v);
        W[v]+=W[i];
    }
}

void sol(int tc) {
    cin >> N >> M;
    vector<pll> edge;
    for(int i=1;i<=N;i++) {
        int u,v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
        I[u]++, I[v]++;
        C[i]=1;
        edge.push_back({u,v});
    }

    queue<int> q;
    for(int i=1;i<=N;i++) if(I[i] == 1) q.push(i);
    while(q.size()) {
        int v = q.front(); q.pop();
        C[v]=0;
        for(int i:G[v]) if(--I[i] == 1) {
            q.push(i);
        }
    }

    dsu d(N+1);
    for(auto [u,v]:edge) {
        if(C[u] && C[v]) continue;
        T[u].push_back(v);
        T[v].push_back(u);
        d.merge(u,v);
    }

    build();

    ll cw=0;
    for(int i=0,u,v,w;i<M;i++) {
        cin >> u >> v >> w;
        W[u]+=w, W[v]+=w;
        if(d.same(u,v)) {
            W[lca(u,v)]-=w*2;
        } else {
            cw+=w;
        }
    }

    for(int i=1;i<=N;i++) if(C[i]) d2(i);

    for(auto [u,v]:edge) {
        if(C[u] && C[v]) cout << cw << endl;
        else if(D[u] < D[v]) cout << W[v] << endl;
        else cout << W[u] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}