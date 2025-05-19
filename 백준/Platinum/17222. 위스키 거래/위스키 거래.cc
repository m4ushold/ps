#include <bits/stdc++.h>
using namespace std;

const int sz = 303;
int N, M, C[sz][sz], F[sz][sz], A[sz];
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
    for(int i=1;i<=N+M;i++) cin >> A[i];
    for(int i=N+1,k;i<=N+M;i++) {
        cin >> k;
        while(k--) {
            int x; cin >> x;
            G[i].push_back(x), G[x].push_back(i);
            C[i][x]=A[x];
        }
    }
    for(int i=1;i<=N+M;i++) {
        if(i<=N) G[i].push_back(201), G[201].push_back(i), C[i][201]=C[201][i]=1e9;
        else G[i].push_back(202), G[202].push_back(i), C[i][202]=C[202][i]=A[i];
    }
    cout << mxf(202,201);
    return 0;
}