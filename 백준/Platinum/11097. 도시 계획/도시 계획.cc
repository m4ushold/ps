#include <bits/stdc++.h>
using namespace std;

const int MAX_V=303;
int N, M, ID[MAX_V], A[MAX_V][MAX_V];
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
    for(int i=1;i<=N;i++) G[i].clear(), R[i].clear();
    V.clear(), SCC.clear();
    memset(A, 0, sizeof(A));
    memset(ID, 0, sizeof(ID));

    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        char c; cin >> c;
        if(i!=j) A[i][j]=c-48;
    }
    for(int k=1;k<=N;k++) for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(A[i][k] && A[k][j] && A[i][j]) A[i][j]=0;
    }

    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(A[i][j]) G[i].push_back(j), R[j].push_back(i);
    }
    
    int n=getSCC();
    vector<pair<int,int>> dap;
    for(int i=1;i<=N;i++) for(int j:G[i]) if(ID[i]!=ID[j]) dap.push_back({i,j});
    for(auto vec:SCC) {
        for(int i=0,j=vec.size()-1;i<vec.size();j=i++) {
            if(vec[i]^vec[j]) dap.push_back({vec[i],vec[j]});
        }
    }
    cout << dap.size() << '\n';
    for(auto [i,j]:dap) cout << i << ' ' << j << '\n';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}