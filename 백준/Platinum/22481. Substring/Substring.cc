#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

template <ll P, ll M> struct Hashing {
  vector<ll> B, H;
  void build(const string &s) {
    B.resize(s.size() + 1), H.resize(s.size() + 1);
    B[0] = 1;
    for (int i = 1; i <= s.size(); i++)
      H[i] = (H[i - 1] * P + s[i - 1]) % M, B[i] = B[i - 1] * P % M;
  }
  ll get(int s, int e) {
    return ((H[e] - H[s - 1] * B[e - s + 1]) % M + M) % M;
  }
};

Hashing<917, 998244353> H1;
Hashing<100003, 1000000103> H2;

void sol(int tc) {
  int n, m;
  cin >> n >> m;
  int l = 1, r = 1;
  vector<pll> v;
  string s;
  cin >> s;
  H1.build(s), H2.build(s);
  for (int i = 0; i < m; i++) {
    string op;
    cin >> op;
    if (op == "L++")
      l++;
    else if (op == "L--")
      l--;
    else if (op == "R++")
      r++;
    else
      r--;
    v.push_back({H1.get(l, r), H2.get(l, r)});
  }
  prs(v);
  cout << v.size() << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}