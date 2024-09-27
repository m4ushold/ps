#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, V[10101];
vector<int> G[10101];

int dfs(int v) {
    V[v]=1;
    int res=1;
    for(int i:G[v]) if(!V[i]) res+=dfs(i);
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,u,v;i<M;i++) cin >> u >> v, G[v].push_back(u);
    vector<int> v;
    int mx=0;
    for(int i=1,a;i<=N;i++) {
        memset(V, 0, sizeof(V));
        a=dfs(i);
        if(mx<a) v.clear(), mx=a;
        if(mx==a) v.push_back(i);
    }
    for(int i:v) cout << i << ' ';
    return 0;
}