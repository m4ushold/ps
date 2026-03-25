#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

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

int op(int a, int b) { return a + b; }
int e() { return 0; }

void sol(int tc) {
  int n, q;
  cin >> n >> q;
  vector<int> v(n + 1, 1);
  segtree<int, op, e> seg(v);
  for (int i = 0, l, r, x; i < q; i++) {
    char op;
    cin >> op;
    if (op == 'R')
      cin >> x, seg.set(x, 0);
    else
      cin >> l >> r, cout << seg.prod(l, r + 1) << endl;
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