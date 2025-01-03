#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAX_V=10101;
vector<int> G[MAX_V];
int In[MAX_V], Low[MAX_V], P[MAX_V];

void dfs(int v, int p=0) {
    static int pv=0;
    In[v]=Low[v]=++pv, P[v]=p;
    for(auto i:G[v]) if(i!=p) {
        if(!In[i]) dfs(i,v), Low[v]=min(Low[v], Low[i]);
        else Low[v]=min(Low[v], In[i]);
    }
}

vector<int> cutVertex(int n){
    for(int i=1;i<=n;i++) if(!In[i]) dfs(i);
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=0,a,b;i<m;i++) cin >> a >> b, G[a].push_back(b), G[b].push_back(a);
    vector<int> v=cutVertex(n);
    cout << v.size() << '\n';
    for(int i:v) cout << i << " ";
    return 0;
}
