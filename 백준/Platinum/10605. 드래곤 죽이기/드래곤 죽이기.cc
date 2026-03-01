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
};

void sol(int n, int m, int k) {
  dsu d(n);
  vector<vector<pll>> v(n);
  for(int i=0,a,b;i<m;i++) cin >> a >> b, d.merge(a-1,b-1);
  for(int i=0;i<k;i++) {
    int c,s,nn; cin >> c >> s >> nn;
    v[d.leader(c-1)].push_back({nn,s});
  }
  ll sum = 0;
  for(int i=0;i<n;i++) if(i == d.leader(i)) {
    sort(rall(v[i]));
    int sz = v[i].size();
    vector<int> sfx(sz+1);
    for(int j=sz-1;j>=0;j--) {
      sfx[j] = max<ll>(sfx[j+1], v[i][j].first+1);
    }
    ll cnt=0, mn = sfx[0];
    for(int j=0;j<sz;j++) {
      cnt += v[i][j].second;
      mn = min<ll>(mn, max<ll>(cnt, sfx[j+1]));
    }
    sum += mn;
  }
  cout << sum << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n,m,k;
  while(cin >> n >> m >> k && n) sol(n,m,k);
  return 0;
}