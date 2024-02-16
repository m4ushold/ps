#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp{
  int n, m;
  vector<vector<int>> g;
  vector<int> dst, le, ri;
  vector<char> visit, track;
  HopcroftKarp(int n, int m) : n(n), m(m), g(n), dst(n), le(n, -1), ri(m, -1), visit(n), track(n+m) {}
  void add_edge(int s, int e){ g[s].push_back(e); }
  bool bfs(){
    bool res = false; queue<int> que;
    fill(dst.begin(), dst.end(), 0);
    for(int i=0; i<n; i++)if(le[i] == -1)que.push(i),dst[i]=1;
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(auto i : g[v]){
        if(ri[i] == -1) res = true;
        else if(!dst[ri[i]])dst[ri[i]]=dst[v]+1,que.push(ri[i]);
      }
    }
    return res;
  }
  bool dfs(int v){
    if(visit[v]) return false; visit[v] = 1;
    for(auto i : g[v]){
      if(ri[i] == -1 || !visit[ri[i]] && dst[ri[i]] == dst[v] + 1 && dfs(ri[i])){
        le[v] = i; ri[i] = v; return true;
      }
    }
    return false;
  }
  int maximum_matching(){
    int res = 0; fill(le.begin(),le.end(), -1); fill(ri.begin(),ri.end(), -1);
    while(bfs()){
      fill(visit.begin(), visit.end(), 0);
      for(int i=0; i<n; i++) if(le[i] == -1) res += dfs(i);
    }
    return res;
  }
  void dfs_track(int v){
    if(track[v]) return; track[v] = 1;
    for(auto i : g[v]) track[n+i] = 1, dfs_track(ri[i]);
  }
  tuple<vector<int>, vector<int>, int> minimum_vertex_cover(){
    int matching = maximum_matching(); vector<int> lv, rv;
    fill(track.begin(), track.end(), 0);
    for(int i=0; i<n; i++) if(le[i] == -1) dfs_track(i);
    for(int i=0; i<n; i++) if(!track[i]) lv.push_back(i);
    for(int i=0; i<m; i++) if(track[n+i]) rv.push_back(i);
    return {lv, rv, lv.size() + rv.size()}; // s(lv)+s(rv)=mat
  }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    HopcroftKarp bi(n,m);
    for(int i=0,t,a;i<n;i++) {
        cin >> t;
        while(t--) cin >> a, bi.add_edge(i,a-1);
    }

    auto [a,b,c]=bi.minimum_vertex_cover();
    cout << c << '\n' << a.size() << ' ';
    for(int i:a) cout << i+1 << ' ';
    cout << '\n' << b.size() << ' ';
    for(int i:b) cout << i+1 << ' ';
    cout << '\n';
    return 0;
}