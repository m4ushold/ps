#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 303030;
ll N, M, P[sz], S[sz], W[sz], R[sz], D[sz];
vector<int> G[sz];
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }

void dfs(int v) {
    for(int i:G[v]) D[i]+=D[v], dfs(i);
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> R[i], P[i]=i, S[i]=1;
    vector<array<ll,3>> edge;
    for(int i=0;i<M;i++) {
        int a,b; cin >> a >> b;
        edge.push_back({max(R[a], R[b]), a, b});
    }
    sort(all(edge));

    for(auto [w,u,v]:edge) {
        u=Find(u), v=Find(v);
        if(u == v) continue;
        if(S[u] > S[v]) swap(u,v);

        D[u] += S[v]*w;
        D[v] += S[u]*w;
        D[u] -= D[v];

        G[v].push_back(u);

        P[u]=v;
        S[v]+=S[u];
    }
    dfs(Find(1));

    for(int i=1;i<=N;i++) cout << D[i]+R[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}