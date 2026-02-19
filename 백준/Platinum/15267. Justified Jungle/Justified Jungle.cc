#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<20;
int N, D[sz], S[sz];
vector<int> G[sz];

void dfs(int v=1, int p=-1) {
  D[v]=1;
  for(int i:G[v]) if(i!=p) {
    dfs(i,v);
    D[v] += D[i];
  }
  S[D[v]]++;
}

void sol(int tc) {
  cin >> N;
  for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
  dfs();

  vector<int> v;
  for(int i=1;i<N;i++) if(N%i==0) {
    int sum = 0;
    for(int j=i;j<=N;j+=i) sum += S[j];
    if(sum == N/i) v.push_back(N/i-1);
  }
  reverse(all(v));
  for(int i:v) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}