#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<20;
int N, M, Q, D[sz], P[22][sz];
vector<int> G[sz];

void dfs(int v=1, int p=-1) { for(auto i:G[v]) if(i!=p) D[i]=D[v]+1, P[0][i]=v, dfs(i,v); }

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

void build() {
  dfs();
  for(int i=1;i<22;i++) for(int j=1;j<=N*M;j++) P[i][j]=P[i-1][P[i-1][j]];
}

int dst(int u, int v) {
  return D[u] + D[v] - D[lca(u,v)] * 2;
}

int idx(int u, int v) {
  return (u-1)*M+v;
}

void sol(int tc) {
  cin >> N >> M;
  cin.ignore();
  string s;
  vector<string> A(N+1);
  for(auto &i:A) getline(cin, i);
  for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
    if(j < M && A[i][2*j] == ' ') {
      int u = idx(i,j), v = idx(i,j+1);
      G[u].push_back(v), G[v].push_back(u);
    }
    if(i < N && A[i][j*2-1] == ' ') {
      int u = idx(i,j), v = idx(i+1,j);
      G[u].push_back(v), G[v].push_back(u);
    }
  }
  
  build();

  cin >> Q;
  int a,b,x; cin >> a >> b;
  x = idx(a,b);

  ll ans = 0;
  for(int i=2,a,b;i<=Q;i++) {
    cin >> a >> b;
    int y = idx(a,b);
    ans += dst(x,y);
    x = y;
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