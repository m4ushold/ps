#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1010;
int N, K, ID[MAX_V], D[MAX_V], VI[MAX_V], W[MAX_V], A[MAX_V], DP[MAX_V][MAX_V];
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
    ID[v]=c-1; SCC.back().push_back(v);
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

int dfs(int i) {
    if(VI[i]) return 0;
    VI[i]=1;
    int res=0;
    for(int j:SCC[i]) for(auto k:G[j]) {
        if(ID[k]!=ID[j]) res+=dfs(ID[k]);
    }
    return SCC[i].size()+res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1,a;i<=N;i++) cin >> a, G[a].push_back(i), R[i].push_back(a);

    int n=getSCC(), j=1;
    for(int i=0;i<n;i++) if(!VI[i]) {
        W[j]=SCC[i].size();
        A[j]=dfs(i);
        j++;
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=K;j++) {
            if (j-W[i] >=0) DP[i][j] = max(DP[i-1][j], DP[i-1][j-W[i]]+A[i]);
            else DP[i][j]=DP[i-1][j];
        }
    }
    
    cout << min(DP[N][K],K);
    return 0;
}