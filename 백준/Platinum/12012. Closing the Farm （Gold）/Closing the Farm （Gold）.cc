#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int P[202020], S[202020], U[202020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

vector<int> G[202020];

void sol(int tc) {
    int n,m; cin >> n >> m;
    init(n);
    for(int i=0;i<m;i++) {
        int u,v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    vector<int> q(n), ans(n);
    for(int &i:q) cin >> i;
    reverse(q.begin(),q.end());
    for(int i=0;i<n;i++) {
        int x = q[i];
        U[x]=1;
        for(int j:G[x]) if(U[j]) Union(x,j);
        ans[i] = S[Find(x)] == i+1;
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans) cout << (i?"YES\n":"NO\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}