#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <numeric>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, C[22][22];
double D[22], DD[22];

void sol(int tc) {
  C[0][0] = 1;
  for (int i = 1; i < 22; i++) {
    C[i][0] = 1;
    for (int j = 1; j < 22; j++)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }

  cin >> N;
  double p, q;
  cin >> p >> q;
  for (int i = 0; i <= N; i++)
    D[i] = C[N][i] * pow(q, i) * pow(1 - q, N - i);

  double mx = 0;
  for (int x = 0; x <= N; x++) {
    for (int j = 0; j <= x; j++)
      DD[j] = C[x][j] * pow(p, j) * pow(1 - p, x - j);

    double e = 0;
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= x; j++) {
        int score = i + j > N ? 0 : i + j;
        e += score * D[i] * DD[j];
      }
    mx = max(mx, e);
  }
  cout << fixed << setprecision(12) << mx << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}