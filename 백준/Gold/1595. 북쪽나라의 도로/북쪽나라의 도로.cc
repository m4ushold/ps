#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, D[10101];
vector<pll> G[10101];

void dfs(int v, int p=-1) {
    for(auto [i,w]:G[v]) if(i!=p) {
        D[i]=D[v]+w;
        dfs(i,v);
    }
} 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b,c;
    while(cin >> a >> b >> c) G[a].push_back({b,c}), G[b].push_back({a,c}), N++;
    N++;
    dfs(1);
    ll mx=0, r=0;
    for(int i=1;i<=N;i++) if(mx < D[i]) mx=D[i], r=i;
    D[r]=0;
    dfs(r);
    cout << *max_element(D, D+10101);
    return 0;
}