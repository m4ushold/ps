#include <bits/stdc++.h>
using namespace std;

const int MAX_V=101010;
int N, M, ID[MAX_V];
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

void sol() {
    cin >> N;
    memset(ID, 0, sizeof(ID));
    for(int i=0;i<MAX_V;i++) G[i].clear(), R[i].clear();
    V.clear(), SCC.clear();

    int cnt=0;
    for(int i=1;i<=N;i++) {
        int a; cin >> a;
        if(i!=a) G[i].push_back(a), R[a].push_back(i);
        else cnt++;
    }
    getSCC();
    for(auto i:SCC) if(i.size()>1) cnt+=i.size();
    cout << N-cnt << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}