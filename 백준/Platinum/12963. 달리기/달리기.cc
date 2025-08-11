#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;
ll A[2020]={1}, P[2020], S[2020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    int n,m; cin >> n >> m;
    for(int i=1;i<=m;i++) A[i]=A[i-1]*3%mod;
    init(n);
    vector<pair<int,int>> e(m);
    for(auto &[u,v]:e) cin >> u >> v;
    ll ans=0;
    for(int i=m-1;i>=0;i--) {
        auto [u,v]=e[i];
        if((Find(u)==Find(0) && Find(v)==Find(n-1)) || (Find(v)==Find(0) && Find(u)==Find(n-1))) ans=(ans+A[i])%mod;
        else Union(u,v);
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