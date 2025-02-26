#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int P[1010], S[1010];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
vector<int> G[1010];
vector<pair<int,int>> ans;
void dfs(int v=1, int p=-1) {
    for(int i:G[v]) if(i!=p) dfs(i,v);
    for(int i:G[v]) if(i!=p) ans.push_back({v,i});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    init(n);
    vector<pair<ll,ll>> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    vector<array<ll,3>> e(n);
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        auto [a,b] = v[i];
        auto [c,d] = v[j];
        e.push_back({(b+d)/abs(a-c), i+1, j+1});
    }
    sort(e.begin(),e.end(),greater<>());
    ll mst=0;
    for(auto [w,i,j]:e) if(Union(i,j)) mst+=w, G[i].push_back(j), G[j].push_back(i);
    dfs();
    cout << mst << '\n';
    for(auto [i,j]:ans) cout << i << ' ' << j << '\n';
    return 0;
}