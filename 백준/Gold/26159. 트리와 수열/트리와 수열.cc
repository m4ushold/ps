#include <bits/stdc++.h>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr int mod = 1e9 + 7;
ll N, S[101010];
vector<int> G[101010];

void dfs(int v = 1, int p = -1) {
  S[v] = 1;
  for (int i : G[v])
    if (i != p)
      dfs(i, v), S[v] += S[i];
}

void sol(int tc) {
  cin >> N;
  for (int i = 1, u, v; i < N; i++)
    cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
  dfs();

  ll ans = 0;
  vector<ll> v, a(N - 1);
  for (int i = 2; i <= N; i++) {
    v.push_back(S[i] * (N - S[i]));
  }
  for (ll &i : a)
    cin >> i;
  sort(rall(a)), sort(all(v));
  for (int i = 0; i < N - 1; i++)
    ans = (ans + (a[i] * v[i]) % mod) % mod;
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}