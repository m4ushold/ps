#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
  int _n, size, log;
  std::vector<S> d;

  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(v.size()), size(1), log(0) {
    while(size < _n) size <<= 1, ++log;
    d = std::vector<S>(size << 1, e());
    for(int i = 0; i < _n; i++) d[size + i] = v[i];
    for(int i = size - 1; i; i--) update(i);
  }

  void update(int i) {d[i] = op(d[i<<1], d[i<<1|1]);}

  void set(int i, S x) {
    i += size;
    d[i] = x;
    while(i >>= 1) update(i);
  }

  S get(int i) {
    return d[size + i];
  }

  S prod(int l, int r) {
    S a = e(), b = e();
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if(l & 1) a = op(a, d[l++]);
      if(r & 1) b = op(d[--r], b);
    }
    return op(a,b);
  }

  S all_prod() {
    return d[1];
  }
};

int op(int a, int b) {return max(a,b);}
int e() {return 0;}

int lis(vector<int> &v) {
    segtree<int,op,e> seg(v.size() * 5 + 1);
    for(int i:v) {
        seg.set(i, seg.prod(0,i) + 1);
    }
    return seg.all_prod();
}

void sol(int tc) {
    int n; cin >> n;
    string s = "ERSW";
    vector<string> v(n);
    vector<int> a(n);
    for(auto &i:v) cin >> i;
    vector<int> c(202);
    c['C'] = 4;
    int mn = 1e9;
    do {
        for(int i=0;i<4;i++) c[s[i]] = i;
        for(int i=0;i<n;i++) {
            a[i] = n * c[v[i][0]] + stoi(v[i].substr(1));
        }
        mn = min(mn, n-lis(a));
    } while(next_permutation(all(s)));
    cout << mn;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}