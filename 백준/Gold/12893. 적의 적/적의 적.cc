#include <bits/stdc++.h>
using namespace std;

int P[2020], S[2020], G[2020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) { return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    init(n);
    vector<pair<int,int>> vec;
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        vec.emplace_back(u,v);
        if(!G[u]) G[u]=v;
        else Union(v,G[u]);

        if(!G[v]) G[v]=u;
        else Union(u,G[v]);
    }
    for(auto [u,v]:vec) {
        if(Find(u) == Find(v)) {cout << 0; return 0;}
    }
    cout << 1;
    return 0;
}