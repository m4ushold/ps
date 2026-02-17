#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

map<char,int> m({
    {'o',100},
    {'e',10},
    {'g',1},
    {'a',0},
    {'b',-1},
    {'i',-10},
    {'u',-100}
    });

void sol(string s) {
  ll sum=0, mn=0, mx=0;
  for(char c:s) {
    sum += m[c];
    mx = max(mx, sum-mn);
    mn = min(mn, sum);
  }
  cout << mx << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while(1) {
      char c; cin >> c;
      if(c == ' ') continue;
      else if(c == ',') sol(s), s="";
      else if(c == '.') {
        sol(s);
        break;
      } else s+=c;
    }
    return 0;
}