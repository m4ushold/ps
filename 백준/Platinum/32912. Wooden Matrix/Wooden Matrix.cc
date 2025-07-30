#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, D[1010], A[1010][1010];
vector<pair<int,int>> G[1010];
void dfs(int v, int p=-1) {
    for(auto [i,w]:G[v]) if(i!=p) {
        D[i]=D[v]+w;
        dfs(i,v);
    }
}

int PP[1010], S[1010];
void init(int n) { for(int i=1;i<=n;i++) PP[i]=i,S[i]=1; }
int Find(int v) { return PP[v]==v?v:PP[v]=Find(PP[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), PP[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<array<ll,3>> ed;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> A[i][j];
        if(i<j) ed.push_back({A[i][j],i,j});
    }
    sort(ed.begin(),ed.end());
    init(N);
    for(auto [w,u,v]:ed) {
        if(Union(u,v)) G[u].push_back({v,w}), G[v].push_back({u,w});
    }

    for(int i=1;i<=N;i++) {
        memset(D, 0, sizeof(D));
        dfs(i);
        for(int j=1;j<=N;j++) if(D[j] != A[i][j]) {
            return cout << "No", 0;
        }
    }
    cout << "Yes";
    return 0;
}