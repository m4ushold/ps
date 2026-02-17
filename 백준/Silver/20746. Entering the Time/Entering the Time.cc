#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

bool chk(string s) {
  int h=stoi(s.substr(0,2)), m=stoi(s.substr(3,2));
  return 0<=h && h<=23 && 0<=m && m<=59;
}

void sol(int tc) {
  string s,e; cin >> s >> e;
  queue<string> q;
  q.push(s);
  map<string,string> vis;
  while(q.size()) {
    auto v = q.front(); q.pop();
    if(v == e) break;
    for(int i:{0,1,3,4}) {
      string t = v;
      t[i] = (t[i]-48+1)%10+48;
      if(chk(t) && vis.count(t) == 0) {
        vis[t] = v;
        q.push(t);
      }

      t = v;
      t[i] = (t[i]-48+9)%10+48;
      if(chk(t) && vis.count(t) == 0) {
        vis[t] = v;
        q.push(t);
      }
    }
  }

  vector<string> ans;
  ans.push_back(e);
  while(ans.back() != s) {
    ans.push_back(vis[ans.back()]);
  }
  reverse(all(ans));
  cout << ans.size() << endl;
  for(auto i:ans) cout << i << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}