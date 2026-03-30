#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

using real_t = double;
using cpx = complex<real_t>;
constexpr real_t PI = acos(-1);
constexpr int mod = 104857601;
void FFT(vector<cpx> &a, bool inv_fft = false) {
  int n = a.size();
  for (int i = 1, j = 0, bit; i < n; i++) {
    for (bit = n / 2; j >= bit; bit /= 2)
      j -= bit;
    if (i < (j += bit))
      swap(a[i], a[j]);
  }
  vector<cpx> root(n / 2);
  long double ang = 2 * acosl(-1) / n * (inv_fft ? -1 : 1);
  for (int i = 0; i < n / 2; i++)
    root[i] = cpx(cosl(ang * i), sinl(ang * i));
  for (int i = 2; i <= n; i *= 2) {
    int step = n / i;
    for (int j = 0; j < n; j += i) {
      for (int k = 0; k < i / 2; k++) {
        auto u = a[j + k], v = a[j + k + i / 2] * root[step * k];
        a[j + k] = u + v;
        a[j + k + i / 2] = u - v;
      }
    }
  }
  if (inv_fft)
    for (int i = 0; i < n; i++)
      a[i] /= n;
}

// ================= [ 2. ConvMod (Arbitrary Modulo) ] =================
// 임의의 모듈러(1e9+7 등) 곱셈. (Splitting FFT 이용)
// 사용법: vector<ll> res = ConvMod(a, b, 1000000007);
vector<ll> ConvMod(const vector<ll> &a, const vector<ll> &b,
                   unsigned long long mod) {
  if (a.empty() || b.empty())
    return {};
  int sz = a.size() + b.size() - 1, n = 1;
  while (n < sz)
    n <<= 1;
  vector<cpx> l(n), r(n), outs(n), outl(n);
  for (int i = 0; i < a.size(); i++)
    l[i] = cpx(a[i] >> 15, a[i] & 32767);
  for (int i = 0; i < b.size(); i++)
    r[i] = cpx(b[i] >> 15, b[i] & 32767);
  FFT(l);
  FFT(r);
  for (int i = 0; i < n; i++) {
    int j = -i & (n - 1);
    outl[j] = (l[i] + conj(l[j])) * r[i] / (2. * n);
    outs[j] = (l[i] - conj(l[j])) * r[i] / (2. * n) / 1i;
  }
  FFT(outl);
  FFT(outs);
  vector<ll> res(sz);
  for (int i = 0; i < res.size(); i++) {
    ll av = llround(real(outl[i])), cv = llround(imag(outs[i]));
    ll bv = llround(imag(outl[i])) + llround(real(outs[i]));
    res[i] = ((((av % mod << 15) + bv) % mod << 15) + cv) % mod;
  }
  return res;
}

ll pw(ll a, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod, n >>= 1;
  }
  return res;
}

// calculate f^{-1} mod x^n
vector<ll> polynomial_inv(vector<ll> &f, int n) {
  vector<ll> g{pw(f[0], mod - 2)};

  int sz = 1;
  while (sz < n) {
    sz <<= 1;
    vector<ll> ff(f.begin(), f.begin() + min<int>(f.size(), sz));
    vector<ll> fg = ConvMod(ff, g, mod);
    for (int i = 0; i < fg.size(); i++)
      fg[i] = (mod - fg[i]) % mod;
    fg[0] = (fg[0] + 2) % mod;
    fg.resize(sz);
    g = ConvMod(g, fg, mod);
    g.resize(sz);
  }
  g.resize(n);
  return g;
}

vector<ll> ConvRem(vector<ll> f, vector<ll> g, vector<ll> &p_gri) {
  int n = f.size(), m = g.size();
  if (n < m)
    return f;
  vector<ll> fr(rall(f)), gr(rall(g)),
      gri(p_gri.begin(), p_gri.begin() + n - m + 1);
  vector<ll> qr = ConvMod(fr, gri, mod);
  qr.resize(n - m + 1);

  vector<ll> q(rall(qr));
  vector<ll> gq = ConvMod(g, q, mod);
  vector<ll> r(m - 1);
  for (int i = 0; i < r.size(); i++)
    r[i] = (f[i] - gq[i] % mod + mod) % mod;
  return r;
}

vector<ll> kitamasa(vector<ll> &m, ll n) {
  vector<ll> res{1}, a{0, 1}, mr(rall(m));
  vector<ll> gri = polynomial_inv(mr, m.size());
  while (n) {
    if (n & 1) {
      res = ConvMod(res, a, mod);
      res = ConvRem(res, m, gri);
    }
    a = ConvMod(a, a, mod);
    a = ConvRem(a, m, gri);
    n >>= 1;
  }
  return res;
}

void sol(int tc) {
  ll k, n;
  cin >> k >> n;
  vector<ll> a(k), c(k + 1);
  for (ll &i : a)
    cin >> i;
  for (int i = k - 1; i >= 0; i--)
    cin >> c[i], c[i] = (mod - c[i] % mod) % mod;
  c.back() = 1;

  if (n <= k) {
    cout << a[n - 1] << endl;
    return;
  }
  c.back() = 1;
  vector<ll> f = kitamasa(c, n - 1);

  ll ans = 0;
  for (int i = 0; i < f.size(); i++)
    ans += f[i] * a[i] % mod, ans %= mod;

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
