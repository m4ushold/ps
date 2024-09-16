#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, K, C[101010], A[101010], P[101010];
map<int,int> MP[101010];

int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
void Union(int u, int v, ll w) {
    u=Find(u), v=Find(v);
    if(MP[u].size()>MP[v].size()) swap(u,v);
    if (u!=v) {
        P[u]=v;
        for(auto [i,j]:MP[u]) A[i]+=j*MP[v][i]*w;
        for(auto [i,j]:MP[u]) MP[v][i]+=j;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> M;
    for(int i=1;i<=N;i++) cin >> C[i], MP[i][C[i]]=1, P[i]=i;
    vector<tuple<int,int,int>> v(M);
    for(auto &[w,x,y]:v) cin >> x >> y >> w;
    sort(v.begin(),v.end(),greater<>());
    for(auto &[w,x,y]:v) Union(x,y,w);
    for(int i=1;i<=K;i++) cout << A[i] << '\n';
    return 0;
}