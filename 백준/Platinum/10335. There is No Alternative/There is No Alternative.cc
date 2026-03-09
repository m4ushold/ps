#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<pll> G[505];
int N, M, A[505], W[505], D[505], P[505];

struct dsu {
    int n;
    vector<int> p;
    dsu(int n) : p(n,-1), n(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    bool merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, true);
    }
};

void dfs(int v = 1, int p = -1) {
  for(auto [i,w]:G[v]) if(i != p) {
    P[i] = v;
    D[i] = D[v] + 1;
    W[i] = w;
    dfs(i,v);
  }
}

void fn(int u, int v, int w) {
  while(u!=v) {
    if(D[u] < D[v]) swap(u,v);
    if(W[u] == w) A[u] = 1;
    u = P[u];
  }
}

void sol(int tc) {
  cin >> N >> M;
  vector<array<int,3>> edge(M), asdf;
  for(auto &[w,u,v]:edge) cin >> u >> v >> w;
  sort(all(edge));
  dsu d(N+1);
  for(auto [w,u,v]:edge) {
    if(d.merge(u,v)) {
      G[u].push_back({v,w});
      G[v].push_back({u,w});
    } else asdf.push_back({u,v,w});
  }
  dfs();
  for(auto [u,v,w]:asdf) fn(u,v,w);

  ll cnt = 0, sum = 0;
  for(int i=2;i<=N;i++) if(A[i] == 0) {
    cnt++;
    sum += W[i];
  }
  cout << cnt << ' ' << sum << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}