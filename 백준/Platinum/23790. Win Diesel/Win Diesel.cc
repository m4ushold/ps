#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<18;
int N, M, D[sz], P[22][sz], DD[sz], F[sz];
vector<int> G[sz], I[sz];

void dfs(int v, int b=-1) {
    for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v);
}

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
    return D[u]+D[v]-D[l]*2;
}

void build() {
    dfs(0);
    for(int i=1;i<22;i++) for(int j=0;j<N;j++) P[i][j]=P[i-1][P[i-1][j]];
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=0,a,b;i<M;i++) cin >> a >> b, I[a].push_back(b), I[b].push_back(a);
    queue<int> q;
    q.push(0), F[0]=1;
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:I[v]) {
            if(!F[i]) {
                DD[i] = DD[v] + 1;
                q.push(i), F[i]=1;
            }
        }
    }

    vector<pll> v;
    for(int i=1;i<N;i++) {
        int p = 1e9;
        for(int j:I[i]) {
            if(DD[j]+1 == DD[i]) p=min(p,j);
        }
        
        G[p].push_back(i); 
        v.push_back({DD[i],i});
    }

    build();
    ll x=0, ans=0;
    sort(all(v));
    for(auto [y,z]:v) {
        ans += dst(x,z);
        x=z;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}