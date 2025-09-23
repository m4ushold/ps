#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, K, D[202020], A[202020], D2[202020], D3[202020];
vector<pll> G[202020];

void dfs(int v, int p=-1, int f=1) {
    for(auto [i,w]:G[v]) if(i!=p) {
        if(f) D[i]=D[v]+w;
        else D2[i]=D2[v]+w;
        dfs(i,v,f);
    }
}

void sol(int tc) {
    cin >> N >> K;
    for(int i=1;i<=K;i++) {
        int x; cin >> x;
        A[x]=1;
    }
    for(int i=1;i<N;i++) {
        int u,v,w; cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(1);
    ll x=0,y=0,mx=0;
    for(int i=1;i<=N;i++) {
        if(A[i] && mx < D[i]) mx=D[i], x=i;
    }
    D[x]=0, dfs(x), mx=0;
    for(int i=1;i<=N;i++) {
        if(A[i] && mx < D[i]) mx=D[i], y=i;
    }
    dfs(y,-1,0);
    
    priority_queue<pll,vector<pll>,greater<>> pq;
    for(int i=1;i<=N;i++) {
        if(A[i]) pq.push({0,i}), D3[i]=0;
        else D3[i]=LLONG_MAX/4;
    }
    while(pq.size()) {
        auto [c,v] = pq.top(); pq.pop();
        for(auto [i,w]:G[v]) {
            if(D3[v] + w < D3[i]) {
                D3[i] = D3[v]+w;
                pq.push({D3[i],i});
            }
        }
    }

    pll ans={0,1};
    for(int i=1;i<=N;i++) {
        ll mn=D3[i], mx=max(D[i],D2[i]);
        ll g = gcd<ll>(mn, mx);
        mn/=g, mx/=g;
        if(ans.first * mx < mn * ans.second) ans = {mn,mx};
    }
    cout << ans.first << '/' << ans.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}