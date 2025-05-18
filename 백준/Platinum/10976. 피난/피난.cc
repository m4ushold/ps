#include <bits/stdc++.h>
using namespace std;

const int sz = 202;
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

void sol() {
    cin >> N >> M;
    memset(C, 0, sizeof(C)), memset(F, 0, sizeof(F));
    for(int i=1;i<=N;i++) G[i].clear();
    for(int i=1,x,y;i<=M;i++) {
        cin >> x >> y;
        if(x>y) swap(x,y);
        if(x==1 || y==N) C[x][y]=1;
        else C[x][y]=1e9;
        G[x].push_back(y), G[y].push_back(x);
    }
    cout << mxf(1,N) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}