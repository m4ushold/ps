#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int G[101][101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t,tt=1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        memset(G, 0, sizeof G);
        for(int i=0,s,e;i<m;i++) cin >> s >> e, G[s][e]=G[e][s]=1;
        int k; cin >> k;
        cout << "Data Set " << tt++ << ":\n";
        int cnt=0;
        for(int i=1;i<=n;i++) if(G[k][i]) cout << i << ' ', ++cnt;
        cout << "\n\n";
    }
    return 0;
}