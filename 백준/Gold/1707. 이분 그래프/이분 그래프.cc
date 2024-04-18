#include <bits/stdc++.h>
using namespace std;

int N, M, C[20202];
vector<int> G[20202];

bool dfs(int v=1, int c=1) {
    if(C[v]) return C[v]==c;
    C[v]=c;
    for(int i:G[v]) if(!dfs(i,-c)) return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        for(int i=0;i<20202;i++) G[i].clear(), C[i]=0;
        cin >> N >> M;
        for(int i=0,s,e;i<M;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
        int f=1;
        for(int i=1;i<=N;i++) if(!C[i]) f&=dfs(i);
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}