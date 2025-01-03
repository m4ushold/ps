#include <bits/stdc++.h>
using namespace std;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    int s,e; cin >> s >> e;
    vector<array<int,3>> v(m);
    for(auto &[w,u,v]:v) cin >> u >> v >> w;
    sort(v.begin(),v.end(),greater<>());
    init(n);
    for(auto [w,u,v]:v) {
        Union(u,v);
        if(Find(s)==Find(e)) return cout << w, 0;
    }
    return cout << 0, 0;
}