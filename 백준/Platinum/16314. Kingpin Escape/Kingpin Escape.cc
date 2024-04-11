#include <bits/stdc++.h>
using namespace std;

int N, H;
vector<int> G[101010], V;

void dfs(int v, int p=-1) {
    for(int i:G[v]) if(i!=p) dfs(i,v);
    if(G[v].size()==1) V.push_back(v);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> H;
    for(int i=1,s,e;i<N;i++) {
        cin >> s >> e;
        G[s].push_back(e), G[e].push_back(s);
    }
    dfs(H);

    vector<pair<int,int>> dap;
    for(int i=0;i<V.size()/2;i++) {
        dap.emplace_back(V[i], V[i+V.size()/2]);
    }
    if(V.size()&1) dap.emplace_back(V.front(), V.back());
    
    cout << dap.size() << '\n';
    for(auto [a,b]:dap) cout << a << ' ' << b << '\n';
    return 0;
}