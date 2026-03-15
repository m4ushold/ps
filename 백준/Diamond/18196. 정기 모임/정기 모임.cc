#include <bits/stdc++.h>
#include <cstdint>
#include <sys/types.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, Q, D[606060], P[22][606060], W[606060], IN[606060], RIN[606060];
vector<int> G[606060];

void dfs(int v, int b = -1) {
  static int pv = 0;
  IN[v] = ++pv;
  RIN[IN[v]] = v;
  for (auto i : G[v])
    if (i != b)
      D[i] = D[v] + 1, P[0][i] = v, dfs(i, v);
}

int lca(int u, int v) {
  if (D[u] < D[v])
    swap(u, v);
  int diff = D[u] - D[v];
  for (int i = 0; diff; i++, diff >>= 1)
    if (diff & 1)
      u = P[i][u];
  if (u == v)
    return u;
  for (int i = 21; i >= 0; i--)
    if (P[i][u] != P[i][v])
      u = P[i][u], v = P[i][v];
  return P[0][u];
}

void build(int rt) {
  dfs(rt);
  for (int i = 1; i < 22; i++)
    for (int j = 1; j <= 2*N-1; j++)
      P[i][j] = P[i - 1][P[i - 1][j]];
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  int _n, size, log;
  std::vector<S> d;

  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(v.size()), size(1), log(0) {
    while (size < _n)
      size <<= 1, ++log;
    d = std::vector<S>(size << 1, e());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i; i--)
      update(i);
  }

  void update(int i) { d[i] = op(d[i << 1], d[i << 1 | 1]); }

  void set(int i, S x) {
    i += size;
    d[i] = x;
    while (i >>= 1)
      update(i);
  }

  S get(int i) { return d[size + i]; }

  S prod(int l, int r) {
    S a = e(), b = e();
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        a = op(a, d[l++]);
      if (r & 1)
        b = op(d[--r], b);
    }
    return op(a, b);
  }

  S all_prod() { return d[1]; }
};

struct dsu {
  int n;
  vector<int> p;
  dsu(int n) : p(n, -1), n(n) {}
  int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
  int size(int a) { return -p[leader(a)]; }
  bool same(int a, int b) { return leader(a) == leader(b); }
  void merge(int a, int b) {
    a = leader(a), b = leader(b);
    if (a == b)
      return;
    p[a] += p[b];
    p[b] = a;
  }
};

pll op(pll a, pll b) {
  return {min(a.first, b.first), max(a.second, b.second)};
}
pll e() { return {INTMAX_MAX, INTMAX_MIN}; }

void sol(int tc) {
  cin >> N >> Q;
  vector<array<int, 3>> edge;
  for (int i = 1, a, b, c; i < N; i++) {
    cin >> a >> b >> c;
    edge.push_back({c, a, b});
  }
  sort(all(edge));

  dsu d(2 * N + 2);
  int pv = N + 1;
  for (auto [w, u, v] : edge) {
    u = d.leader(u), v = d.leader(v);
    G[pv].push_back(u), G[pv].push_back(v);
    d.merge(pv, u), d.merge(pv, v);
    W[pv] = w;
    pv++;
  }
  build(pv - 1);

  segtree<pll, op, e> seg(N + 1);
  for (int i = 1; i <= N; i++) {
    seg.set(i, {IN[i], IN[i]});
  }

  for (int i = 0, l, r; i < Q; i++) {
    cin >> l >> r;
    auto [a, b] = seg.prod(l, r + 1);
    a = RIN[a], b = RIN[b];
    int p = lca(a, b);
    cout << W[p] << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}