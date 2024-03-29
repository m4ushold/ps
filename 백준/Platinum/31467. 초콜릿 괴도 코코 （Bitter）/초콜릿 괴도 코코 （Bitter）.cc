#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAX_V=1010101;
vector<int> G[MAX_V];
int In[MAX_V], Low[MAX_V], P[MAX_V];

void tarjan(int n){
    int c=0;
    function<void(int,int)> dfs = [&](int v, int p){
        In[v]=Low[v]=++c, P[v]=p;
        for(auto i:G[v]) if(i!=p) {
            if(!In[i]) dfs(i,v), Low[v]=min(Low[v], Low[i]); 
            else Low[v]=min(Low[v], In[i]);
        }
    };
    for(int i=1;i<=n;i++) if(!In[i]) dfs(i, 0);
}
vector<int> cutVertex(int n){
    tarjan(n);
    vector<int> res, isCut(MAX_V);
    function<void(int)> dfs=[&](int v){
        int chd=0;
        for(auto i:G[v]) if(P[i]==v) {
            dfs(i); chd++;
            if(!P[v] && chd>1) isCut[v]=1; 
            else if(P[v] && Low[i]>=In[v]) isCut[v]=1;
        }
    };
    for(int i=1;i<=n;i++) if(!P[i]) dfs(i);
    for(int i=1;i<=n;i++) if(isCut[i]) res.push_back(i);
    return res;
}

int N, A[1010][1010], B[1010][1010], E, V;
char C[1010][1010];

int idx(int i, int j) { return (i-1)*N+j; }
pair<int,int> ridx(int n) { return {n%N?n/N+1:n/N,n%N?n%N:N}; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> C[i][j];
    vector<pair<int,int>> d({{1,0},{-1,0},{0,1},{0,-1}}), dap;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(C[i][j]=='#') {
        V++;
        for(auto [x,y]:d) if(0<min(i+x,j+y) && max(i+x,j+y)<=N && C[i+x][j+y]=='#') 
            G[idx(i,j)].push_back(idx(i+x,j+y)), B[i][j]++, E++;
    }
    E/=2;

    vector<int> v=cutVertex(N*N);
    for(int i:v) A[ridx(i).first][ridx(i).second]=1;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(!A[i][j] && E-B[i][j]==V-2) dap.emplace_back(i,j);
    }

    cout << dap.size() << '\n';
    for(auto [i,j]:dap) cout << i << ' ' << j << '\n';
    return 0;
}
