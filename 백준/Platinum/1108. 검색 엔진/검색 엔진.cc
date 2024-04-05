#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, C[10101];
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
    map<string,int> m;
    vector<ll> d(10101,1);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        string a,b; cin >> a >> M;
        int s, e;
        e=!m[a]?m[a]=m.size():m[a];
        for(int j=0;j<M;j++) {
            cin >> b;
            s=!m[b]?m[b]=m.size():m[b];
            G[s].push_back(e), R[e].push_back(s);
        }
    }
    N=m.size();
    
    getSCC();
    for(auto i:S) for(int j:i) for(int u:G[j]) if(C[u]!=C[j]) d[u]+=d[j];

    string s; cin >> s;
    cout << d[m[s]];
    return 0;
}