#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
ll N;
vector<pair<ll,ll>> G[505050];
map<ll,ll> M;
 
void dfs(int v=1, int p=-1, int ww=0) {
    M[ww]++;
    for(auto [i,w]:G[v]) if(i!=p) {
        dfs(i,v,ww^w);
    }
}
 
void sol(int tc) {
    cin >> N;
    for(int i=1,u,v,w;i<N;i++) cin >> u >> v >> w, G[u].push_back({v,w}), G[v].push_back({u,w});
    dfs();
    ll ans=0;
    for(auto [i,j]:M) ans+=j*(j-1)/2;
    cout << ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}