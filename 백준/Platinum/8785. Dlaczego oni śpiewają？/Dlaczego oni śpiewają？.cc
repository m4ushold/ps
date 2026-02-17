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

bool fn(array<int,3> a, array<int,3> b) {
  auto [ax,ay,ar] = a;
  auto [bx,by,br] = b;
  ll dx=ax-bx, dy=ay-by, r=ar+br;
  return dx*dx + dy*dy <= r*r;
}

void sol(int tc) {
  int n,m,k; cin >> n >> m >> k;
  vector<array<int,3>> v(k);
  for(auto &[x,y,r]:v) cin >> x >> y >> r;
  dsu d(k+2);
  for(int i=0;i<k;i++) for(int j=i+1;j<k;j++) if(fn(v[i], v[j])) {
    d.merge(i,j);
  }
  for(int i=0;i<k;i++) {
    auto [x,y,r] = v[i];
    if(y-r<=0) d.merge(i, k);
    if(y+r>=m) d.merge(i,k+1);
  }
  if(d.same(k,k+1)) cout << "NIE" << endl;
  else cout << "TAK" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}