#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

struct dsu {
    int n;
    vector<int> p;
    dsu(int n) : p(n,-1), n(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, a);
    }
};

void sol(int tc) {
  int n; cin >> n;
  dsu d(n*2);
  vector<int> e(2*n);
  for(int i=0,p,q;i<n;i++) {
    cin >> p >> q;
    --p, --q;
    p = d.leader(p), q = d.leader(q);
    if(d.leader(p) != d.leader(q)) {
      d.merge(p,q);
      e[d.leader(p)] += e[d.leader(p) == p ? q : p];
    }
    e[d.leader(p)]+=1;
  }
  for(int i=0;i<2*n;i++) if(i == d.leader(i) && d.size(i) < e[i]) {
    cout << "impossible" << endl;
    return;
  }
  cout << "possible" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}
