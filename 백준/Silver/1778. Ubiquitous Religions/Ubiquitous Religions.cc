#include <bits/stdc++.h>
using namespace std;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,tc=0;
    while(cin >> n >> m && n) {
        init(n);
        for(int i=0,u,v;i<m;i++) cin >> u >> v, Union(u,v);
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=i==P[i];
        cout << "Case " << ++tc << ": " << cnt << '\n';
    }
    return 0;
}