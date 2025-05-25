#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
ll N, M, A[sz];
vector<int> G[sz];

ll dfs(int v=1, int p=0) {
    ll mx=0, res=0;
    for(int i:G[v]) if(i!=p) {
        res += dfs(i,v);
        mx = max(mx, A[i]);
    }
    if(v == 1) mx = max(mx, A[v]);
    res += mx;
    A[v] = max(0LL, A[v] - mx);
    if(p) A[p] = max(0LL, A[p] - mx);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    cout << dfs();
    return 0;
}