#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, C[303030];
vector<pair<ll,ll>> G[303030];

bool dfs(int v, ll x) {
    if(v==N) return 1;
    C[v]=1;
    for(auto [i,w]:G[v]) if(!C[i] && (x|w)==x) {
        if(dfs(i,x)) return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(ll i=0,s,e,w;i<M;i++) cin >> s >> e >> w, G[s].emplace_back(e,w), G[e].emplace_back(s,w);
    ll x=(1LL<<60)-1;
    for(int i=59;i>=0;i--) {
        memset(C,0,sizeof C);
        if(dfs(1,(1LL<<i)^x)) x^=1LL<<i;
    }
    cout << x;
    return 0;
}