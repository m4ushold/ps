#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using pt=pll;

struct bus{pt s, e; int id;};

int ccw(pt &a, pt &b, pt &c)
{
  ll res=a.x*b.y+b.x*c.y+c.x*a.y;
  res-=b.x*a.y+c.x*b.y+a.x*c.y;
  return (res>0)-(res<0);
}

bool cross(pt a, pt b, pt c, pt d)
{
  int ab=ccw(a,b,c)*ccw(a,b,d);
  int cd=ccw(c,d,a)*ccw(c,d,b);
  if(ab==0&&cd==0) {
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    return !(b<c||d<a);
  }
  return ab<=0&&cd<=0;
}

vector<int> G[5050];

void sol(int tc) {
  int m,n,k; cin >> m >> n >> k;
  vector<bus> v(k);
  for(int i=0;i<k;i++) {
    cin >> v[i].id >> v[i].s.x >> v[i].s.y >> v[i].e.x >> v[i].e.y;
  }

  for(int i=0;i<2;i++) {
    int x,y; cin >> x >> y;
    v.push_back(bus{{x,y},{x,y},i?k+1:0});
  }

  for(int i=0;i<v.size();i++) {
    for(int j=i+1;j<v.size();j++) {
      if(cross(v[i].s, v[i].e, v[j].s, v[j].e)) {
        G[v[i].id].push_back(v[j].id), G[v[j].id].push_back(v[i].id);
      }
    }
  }
  v.clear();

  queue<int> q;
  vector<ll> d(k+2);
  q.push(0);
  while(q.size()) {
    int v = q.front(); q.pop();
    for(int i:G[v]) if(d[i] == 0 && i) {
      d[i] = d[v] + 1;
      q.push(i);
    }
  }
  cout << d[k+1]-1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t=1;
  // cin >> t;
  for(int i=1;i<=t;i++) sol(i);
  return 0;
}