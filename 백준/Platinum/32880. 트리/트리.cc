#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll D[505050][2], C[505050], S[505050], M[505050];
vector<int> G[505050];

void dfs(int v=0, int p=-1) {
  D[v][1] = C[v];
  for(int i:G[v]) if(i != p) {
    dfs(i,v);
    D[v][1] += max(D[i][1], 0LL);
    S[v] += max(D[i][1],0LL);
    D[v][0] = max(D[v][0], D[i][0]);
  }
  D[v][0] = max(D[v][0], D[v][1]);
}

ll dfs2(int v=0, int p=-1, ll d0=LLONG_MIN/4, ll d1=LLONG_MIN/4) {
  ll ans = LLONG_MIN / 4;
  vector<ll> vec;
  vector<pll> aa;
  for(int i:G[v]) if(i != p) vec.push_back(D[i][0]), aa.push_back({D[i][0], i});
  if(v) vec.push_back(d0);

  if(vec.size() > 1) {
    sort(rall(vec));
    ans = max(ans, vec[0] + vec[1]);
  }

  sort(rall(aa));
  for(int i:G[v]) if(i != p) {
    ll td1 = C[v] + max(d1, 0LL) + S[v] - max(0LL, D[i][1]);
    ll mxv = aa[0].second == i ? (aa.size() > 1 ? aa[1].first : LLONG_MIN / 4) : (aa.size() ? aa[0].first : LLONG_MIN / 4);
    ll td0 = max({d0, td1, mxv});
    ans = max(ans, dfs2(i, v, td0, td1));
  }

  return ans;
}

ll findSum(int n, vector<int> c, vector<int> n1, vector<int> n2) {
  for(int i=0;i<n-1;i++) G[n1[i]].push_back(n2[i]), G[n2[i]].push_back(n1[i]);
  for(int i=0;i<n;i++) C[i]=c[i], D[i][0]=C[i];

  dfs();
  return dfs2();
}
