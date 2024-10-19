#include <bits/stdc++.h>
using namespace std;

const int MAX_V=101010;
int N, M, ID[MAX_V], LOW[MAX_V], VI[MAX_V], IN[MAX_V];
vector<int> G[MAX_V], R[MAX_V], V;
vector<vector<int>> SCC;

void dfs1(int v) {
    ID[v]=-1;
    for(auto i:G[v]) if(!ID[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c) {
    ID[v]=c; SCC.back().push_back(v);
    for(auto i:R[v]) if(ID[i]==-1) dfs2(i,c);
}

int getSCC() {
    for(int i=1;i<=N;i++) if(!ID[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(ID[i]==-1) SCC.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e;i<M;i++) cin >> s >> e, G[s].push_back(e), R[e].push_back(s);
    
    int cnt=0, n=getSCC();
    vector<int> in(n+1);
    for(int i=1;i<=N;i++) for(int j:G[i]) in[ID[j]]+=(ID[i]!=ID[j]);
    vector<int> ans;
    for(int i=1;i<=n;i++) if(!in[i]) {
        ans.push_back(*min_element(SCC[i-1].begin(),SCC[i-1].end()));
    }
    sort(ans.begin(),ans.end());
    for(int i:ans) cout << i << '\n';
    return 0;
}