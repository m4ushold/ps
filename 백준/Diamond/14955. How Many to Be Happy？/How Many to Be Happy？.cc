#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MX=505;
int N, M, C[MX][MX], F[MX][MX];
vector<int> G[MX];
vector<pair<int,int>> A[MX];

int mxf(int s, int t) {
    memset(F, 0, sizeof(F));
    int mf=0;
    while(1) {
        vector<int> par(MX,-1);
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int v=q.front(); q.pop();
            for(int i:G[v]) if(C[v][i]-F[v][i]>0 && par[i]==-1) {
                q.push(i), par[i]=v;
                if(i==t) break;
            }
        }
        if(par[t]==-1) break;

        int mn=1e9;
        for(int i=t;i!=s;i=par[i]) mn=min(mn, C[par[i]][i]-F[par[i]][i]);
        for(int i=t;i!=s;i=par[i]) F[par[i]][i]+=mn, F[i][par[i]]-=mn;
        mf+=mn;
    }
    return mf;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0,u,v,w;i<M;i++) {
        cin >> u >> v >> w;
        A[w].push_back({u,v});
    }

    ll ans=0;
    for(int i=1;i<MX;i++) {
        for(auto [u,v]:A[i]) ans += mxf(u,v);
        for(auto [u,v]:A[i]) {
            G[u].push_back(v), G[v].push_back(u);
            C[u][v]=C[v][u]+=1;
        }
    }
    cout << ans;
    return 0;
}