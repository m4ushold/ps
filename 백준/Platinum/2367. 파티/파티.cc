#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K, D, C[333][333], F[333][333];
vector<int> G[333];

int mf(int s=1, int t=2) {
    int mf=0;
    while(1) {
        vector<int> par(333,-1);
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
    cin >> N >> K >> D;
    for(int i=3;i<N+3;i++) {
        G[1].push_back(i); G[i].push_back(1);
        C[1][i]=K;
    }
    for(int i=N+3,a;i<N+D+3;i++) {
        cin >> a;
        G[2].push_back(i); G[i].push_back(2);
        C[i][2]=a;
    }
    for(int i=3,t;i<N+3;i++) {
        cin >> t;
        for(int j=0,a;j<t;j++) {
            cin >> a;
            G[i].push_back(a+N+2); G[a+N+2].push_back(i);
            C[i][a+N+2]=1;
        }
    }
    cout << mf() << '\n';
}