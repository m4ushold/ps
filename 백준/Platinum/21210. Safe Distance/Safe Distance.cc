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
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, true);
    }
    void clear() {for(int &i:p) i = -1;}
};

bool fn(vector<pair<double,double>> &pts, double r, dsu &d, int x, int y) {
  int n = pts.size();
  d.clear();

  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      if(hypot(pts[i].first-pts[j].first, pts[i].second-pts[j].second) <= r*2) d.merge(i,j);
    }

    auto [a,b] = pts[i];
    if(a-r<=0) d.merge(i,n);
    if(a+r>=x) d.merge(i,n+1);
    if(b-r<=0) d.merge(i,n+2);
    if(b+r>=y) d.merge(i,n+3);
  }

  if(d.same(n,n+1) || d.same(n+2,n+3)) return false;
  if(d.same(n,n+2) || d.same(n+1,n+3)) return false;
  return true;
}

void sol(int tc) {
  int x,y,n; cin >> x >> y >> n;
  vector<pair<double,double>> pts(n);
  for(auto &[a,b]:pts) cin >> a >> b;

  dsu d(n+4);

  double l=0,r=1e9;
  for(int i=0;i<100;i++) {
    double m = (l+r)/2;
    if(fn(pts,m,d,x,y)) l=m;
    else r=m;
  }
  cout << fixed << setprecision(12) << l;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t=1;
  // cin >> t;
  for(int i=1;i<=t;i++) sol(i);
  return 0;
}