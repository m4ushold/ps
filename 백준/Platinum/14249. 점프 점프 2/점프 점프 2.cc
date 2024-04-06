#include <bits/stdc++.h>
using namespace std;

const int MAX_V=101010;
int N, M, ID[MAX_V];
vector<int> G[MAX_V], R[MAX_V], V;
vector<vector<int>> SCC;

void dfs1(int v)
{
    ID[v]=-1;
    for(auto i:G[v]) if(!ID[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c)
{
    ID[v]=c; SCC.back().push_back(v);
    for(auto i:R[v]) if(ID[i]==-1) dfs2(i,c);
}

int getSCC()
{
    for(int i=1;i<=N;i++) if(!ID[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(ID[i]==-1) SCC.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int dfs(int v) {
    int mx=0;
    for(int i:SCC[v-1]) for(int j:G[i]) if(v!=ID[j]) {
        mx=max(mx,dfs(ID[j]));
    }
    return mx+SCC[v-1].size();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,n;i<=N;i++) {
        cin >> n;
        if(i-n>0) G[i].push_back(i-n), R[i-n].push_back(i);
        if(i+n<=N) G[i].push_back(i+n), R[i+n].push_back(i);
    }
    getSCC();
    int s; cin >> s;
    cout << dfs(ID[s]);
    return 0;
}