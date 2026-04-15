#include <bits/stdc++.h>
#include <climits>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {

public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S> &v)
      : _n(int(v.size())), size(1), log(0) {
    while (size < _n)
      size <<= 1, ++log;
    d = std::vector<S>(size << 1, e());
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1)
          all_apply(l++, f);
        if (r & 1)
          all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l)
        update(l >> i);
      if (((r >> i) << i) != r)
        update((r - 1) >> i);
    }
  }

private:
  int _n, size, log;
  std::vector<S> d;
  std::vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size)
      lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};

using S = pll;
S op(S a, S b) { return S{max(a.first, b.first), min(a.second, b.second)}; }
S e() { return S{LLONG_MIN, LLONG_MAX}; }
using F = pll;
S mapping(F a, S b) {
  return S{max(a.first, b.first), min(a.second, b.second)};
}
F composition(F a, F b) {
  return S{max(a.first, b.first), min(a.second, b.second)};
}
F id() { return S{LLONG_MIN, LLONG_MAX}; }

struct HLD {
  int n;
  vector<int> TOP, P, D, SZ, IN;
  vector<vector<int>> GG, G;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg;
  HLD(int n) {
    ++n;
    TOP.resize(n);
    P.resize(n);
    D.resize(n);
    SZ.resize(n);
    IN.resize(n);
    G.resize(n);
    GG.resize(n);
    seg = lazy_segtree<S, op, e, F, mapping, composition, id>(n);
  }
  void connect(int u, int v) { GG[u].push_back(v), GG[v].push_back(u); }
  void d1(int v = 1, int p = -1) {
    for (int i : GG[v])
      if (i != p)
        G[v].push_back(i), D[i] = D[v] + 1, P[i] = v, d1(i, v);
  }
  void d2(int v = 1) {
    SZ[v] = 1;
    for (int &i : G[v]) {
      d2(i), SZ[v] += SZ[i];
      if (SZ[i] > SZ[G[v][0]])
        swap(i, G[v][0]);
    }
  }
  void d3(int v) {
    static int pv = 0;
    IN[v] = ++pv;
    for (int i : G[v])
      TOP[i] = (i == G[v][0] ? TOP[v] : i), d3(i);
  }
  void build() { d1(), d2(), d3(TOP[1] = 1); }
  void updatemn(int u, int v, int x) {
    for (; TOP[u] != TOP[v]; u = P[TOP[u]]) {
      if (D[TOP[u]] < D[TOP[v]])
        swap(u, v);

      seg.apply(IN[TOP[u]], IN[u] + 1, {x, LLONG_MAX});
    }
    if (IN[u] > IN[v])
      swap(u, v);
    seg.apply(IN[u] + 1, IN[v] + 1, {x, LLONG_MAX});
  }
  void updatemx(int u, int v, int x) {
    for (; TOP[u] != TOP[v]; u = P[TOP[u]]) {
      if (D[TOP[u]] < D[TOP[v]])
        swap(u, v);
      seg.apply(IN[TOP[u]], IN[u] + 1, {LLONG_MIN, x});
    }
    if (IN[u] > IN[v])
      swap(u, v);
    seg.apply(IN[u] + 1, IN[v] + 1, {LLONG_MIN, x});
  }
};

const int MAX_V = 70707;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

bool dfs(int v) {
  vi[v] = 1;
  for (int i : G[v]) {
    if (B[i] == -1 || !vi[B[i]] && dfs(B[i])) {
      A[v] = i, B[i] = v;
      return 1;
    }
  }
  return 0;
}

int matching(int n) {
  for (int i = 0; i < MAX_V; i++)
    A[i] = B[i] = -1;
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    for (int i = 0; i < MAX_V; i++)
      vi[i] = 0;
    cnt += dfs(i);
  }
  return cnt;
}

void sol(int tc) {
  int n;
  cin >> n;
  HLD tree(n);
  vector<pll> edges(n - 1);
  for (auto &[u, v] : edges)
    cin >> u >> v, tree.connect(u, v);
  tree.build();

  int q;
  cin >> q;
  map<ll, ll> m;
  vector<array<ll, 4>> qry(q);
  for (int i = 0; i < q; i++) {
    auto &[a, b, c, d] = qry[i];
    char t;
    cin >> t >> b >> c >> d;
    a = t;
    m[d] = i;
    if (a == 'M')
      tree.updatemx(b, c, d);
    else
      tree.updatemn(b, c, d);
  }

  for (int i = 0; i < edges.size(); i++) {
    auto [u, v] = edges[i];
    int x = tree.D[u] > tree.D[v] ? u : v;
    auto [l, r] = tree.seg.get(tree.IN[x]);

    if (r != LLONG_MAX && m.count(r) && qry[m[r]][0] == 'M')
      G[m[r]].push_back(i);
    if (l != LLONG_MIN && m.count(l) && qry[m[l]][0] == 'm')
      G[m[l]].push_back(i);
  }

  matching(q);

  for (int i = 0; i < n - 1; i++) {
    auto [u, v] = edges[i];
    int x = tree.D[u] > tree.D[v] ? u : v;
    auto [l, r] = tree.seg.get(tree.IN[x]);
    ll w = 1;
    if (B[i] != -1) {
      w = qry[B[i]][3];
    } else if (r != LLONG_MAX) {
      w = r;
    } else if (l != LLONG_MIN) {
      w = l;
    }
    cout << u << ' ' << v << ' ' << w << endl;
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
