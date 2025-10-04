#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, K;
vector<pll> G[202020];

pll dfs(ll x, int v=1, int p=-1) {
    ll mx1=0, mx2=0, c=0;
    for(auto [i,w]:G[v]) if(i!=p) {
        auto [cnt, ww] = dfs(x, i, v);
        c+=cnt;
        if(ww + w > x) c++, ww=0;
        ww+=w;

        if(mx1 < ww) mx2=mx1, mx1=ww;
        else if(mx2 < ww) mx2=ww;
    }

    if(mx1+mx2>x) c++, mx1=0;
    return {c,mx1};
}

void sol(int tc) {
    cin >> N >> K;
    ll l=1, r=1e9*N;
    for(int i=1;i<N;i++) {
        ll u,v,w; cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        l=max(l,w);
    }
    
    while(l<r) {
        ll m=l+r>>1;
        if(dfs(m).first <= K) r=m;
        else l=m+1;
    }
    cout << r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}