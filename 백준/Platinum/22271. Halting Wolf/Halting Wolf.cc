#include <bits/stdc++.h>
using namespace std;

const int INF=1e5;
int N, C[111][111], F[111][111];
vector<int> G[111];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,n,a;i<=N;i++) {
        string s; cin >> s;
        if(s=="*") cin >> a, C[i][a==1?101:a]=INF;
        else {
            n=stoi(s);
            while(n--) cin >> a, C[i][a==1?101:a]++;
        }
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=101;j++) if(C[i][j] && i!=j) G[i].push_back(j);

    int mf=1, s=1, t=101;
    while(1) {
        vector<int> par(111,-1);
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

    if(mf>INF) cout << "*";
    else cout << mf;

    return 0;
}