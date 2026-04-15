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
S op(S a, S b) { return S{a.first + b.first, a.second + b.second}; }
S e() { return S{0, 0}; }
using F = ll;
S mapping(F f, S s) { return S{s.first + f * s.second, s.second}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

struct HLD {
  int n;
  vector<int> TOP, P, D, SZ, IN;
  vector<vector<int>> GG, G;
  lazy_segtree<S, op, e, F, mapping, composition, id> vseg;
  lazy_segtree<S, op, e, F, mapping, composition, id> eseg;
  HLD(int n) {
    ++n;
    TOP.resize(n);
    P.resize(n);
    D.resize(n);
    SZ.resize(n);
    IN.resize(n);
    G.resize(n);
    GG.resize(n);
    vector<S> a(n, S{0, 1});
    vseg = lazy_segtree<S, op, e, F, mapping, composition, id>(a);
    eseg = lazy_segtree<S, op, e, F, mapping, composition, id>(a);
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
  void update(int u, int v) {
    for (; TOP[u] != TOP[v]; u = P[TOP[u]]) {
      if (D[TOP[u]] < D[TOP[v]])
        swap(u, v);

      vseg.apply(IN[TOP[u]], IN[u] + 1, 1);
      eseg.apply(IN[TOP[u]], IN[u] + 1, 1);
    }
    if (IN[u] > IN[v])
      swap(u, v);
    vseg.apply(IN[u], IN[v] + 1, 1);
    eseg.apply(IN[u] + 1, IN[v] + 1, 1);
  }
  pll qry(int u, int v) {
    ll a = 0, b = 0;
    for (; TOP[u] != TOP[v]; u = P[TOP[u]]) {
      if (D[TOP[u]] < D[TOP[v]])
        swap(u, v);

      a += vseg.prod(IN[TOP[u]], IN[u] + 1).first;
      b += eseg.prod(IN[TOP[u]], IN[u] + 1).first;
    }
    if (IN[u] > IN[v])
      swap(u, v);
    a += vseg.prod(IN[u], IN[v] + 1).first;
    b += eseg.prod(IN[u] + 1, IN[v] + 1).first;
    return {a, b};
  }
};

void sol(int tc) {
  int n, m, q;
  cin >> n >> m >> q;
  HLD tree(n);
  for (int i = 1, u, v; i < n; i++)
    cin >> u >> v, tree.connect(u, v);
  tree.build();
  vector<pll> f(m);
  for (auto &[s, e] : f)
    cin >> s >> e;

  for (int i = 0, op, s, e; i < q; i++) {
    cin >> op;
    if (op == 1)
      cin >> s >> e, tree.update(s, e);
    else {
      cin >> s;
      auto [ss, ee] = f[s - 1];
      pll a = tree.qry(ss, ee);
      cout << a.first - a.second << endl;
    }
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
