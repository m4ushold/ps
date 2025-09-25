#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    int n; cin >> n;
    init(n);
    vector<array<ll,3>> e(n-1);
    for(auto &[w,u,v]:e) cin >> u >> v >> w;
    sort(e.begin(),e.end(),greater<>());
    ll ans=0;
    for(auto [w,u,v]:e) {
        ans += w * S[Find(u)] * S[Find(v)];
        Union(u,v);
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}