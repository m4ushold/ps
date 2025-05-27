#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<20;
ll N, D[sz], S[sz];
vector<int> G[sz];

void dfs(int v=1, int p=-1) {
    S[v]=1;
    for(int i:G[v]) if(i!=p) dfs(i,v), S[v]+=S[i], D[v]-=S[i]*S[i];
    D[v]+=(S[v]-1) * (S[v]-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs();
    for(int i=1;i<=N;i++) {
        ll a = S[i], b = N-S[i]+1;
        cout << D[i] + a*b*2-2 << '\n';
    }
    return 0;
}