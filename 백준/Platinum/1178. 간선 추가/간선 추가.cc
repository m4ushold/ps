#include <bits/stdc++.h>
using namespace std;

int V[1010];
vector<int> G[1010];

int dfs(int v) {
    int ret=G[v].size()&1;
    V[v]=1;
    for(int i:G[v]) if(!V[i]) ret+=dfs(i);
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int v,e; cin >> v >> e;
    for(int i=0,u,v;i<e;i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    vector<int> vec;
    for(int i=1;i<=v;i++) if(!V[i]) {
        int t=dfs(i);
        vec.push_back(min(abs(t-0), abs(t-2)));
    }
    int dap=0;
    for(int i:vec) dap+=i/2;
    cout << dap+vec.size()-1;
    return 0;
}