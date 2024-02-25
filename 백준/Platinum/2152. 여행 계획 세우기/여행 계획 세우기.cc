#include <bits/stdc++.h>
using namespace std;

int N, M, C[10101], D[10101];
vector<int> G[10101], R[10101], V;
vector<vector<int>> S;

void dfs1(int v)
{
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c)
{
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC()
{
    for(int i=1;i<=N;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int s, t; cin >> N >> M >> s >> t;
    for(int i=0,s,e;i<M;i++) cin >> s >> e, G[s].push_back(e), R[e].push_back(s);
    getSCC();

    queue<int> q;
    q.push(C[s]); D[C[s]]=S[C[s]-1].size();
    while(!q.empty()) {
        int i=q.front(),t; q.pop();
        for(int v:S[i-1]) for(int u:G[v]) if(C[v]!=C[u]) {
            t=D[C[v]]+(int)S[C[u]-1].size();
            if(D[C[u]]<t) q.push(C[u]), D[C[u]]=t;
        }
    }

    cout << D[C[t]];
    return 0;
}