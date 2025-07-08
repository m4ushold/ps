#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
int N, M, ID[sz], IN[sz];
long double P[sz], D[sz];
vector<int> G[sz], R[sz], V;
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
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        int a,b; char c;
        cin >> a >> c >> b;
        P[i] = (1000-a*1000-b) / 1000.0;
        D[i]=1;
    }
    for(int i=0,s,e;i<M;i++) cin >> s >> e, G[e].push_back(s), R[s].push_back(e);
    int k = getSCC();

    for(auto vec:SCC) {
        for(int v:vec) {
            D[ID[v]]*=P[v];
            for(int i:G[v]) if(ID[i] ^ ID[v]) {
                IN[ID[i]]++;
            }
        }
    }

    long double mx=0;
    for(int i=1;i<=k;i++) if(IN[i] == 0) {
        mx=max(mx, D[i]);
    }
    cout << setprecision(20) << mx;
    return 0;
}