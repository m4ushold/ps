#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, R, C[303030];
vector<int> G[303030];

void dfs(int v=1, int p=-1) {
    for(int i:G[v]) if(p!=i) dfs(i,v), C[v]+=C[i];
    C[v]+=1;
    if(v!=1) R+=C[v]*(C[v]-1)/2 + C[v]*(N-C[v]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    dfs();
    cout << R;
    return 0;
}