#include <bits/stdc++.h>
using namespace std;

const int sz = 303;
int N, M, C[sz][sz], F[sz][sz];
vector<int> G[sz];

int mxf(int s, int t) {
    int mf=0;
    while(1) {
        vector<int> par(sz,-1);
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
    for(int i=0,s,e,c;i<M;i++) {
        cin >> s >> e >> c;
        G[s].push_back(e), G[e].push_back(s);
        C[s][e]=C[e][s]+=c;
    }
    cout << mxf(1,N);
    return 0;
}