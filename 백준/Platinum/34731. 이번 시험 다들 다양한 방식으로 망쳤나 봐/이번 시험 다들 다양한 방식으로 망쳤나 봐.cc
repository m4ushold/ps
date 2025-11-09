#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, X, C[202020], D[202020];
vector<int> G[202020], R[202020], V;
vector<vector<int>> SCC;

void dfs1(int v) {
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c) {
    C[v]=c; SCC.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC() {
    for(int i=1;i<=N;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) SCC.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

void dfs(int v) {
    D[C[v]]=1;
    for(int i:G[v]) if(C[i]!=C[v] && D[C[i]]==0) {
        dfs(i);
    }
}

void sol(int tc) {
    cin >> N >> M >> X;
    for(int i=0;i<M;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }
    int x = getSCC();
    for(int i:SCC[C[X]-1]) dfs(i);
    cout << x - accumulate(D, D+202020, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}