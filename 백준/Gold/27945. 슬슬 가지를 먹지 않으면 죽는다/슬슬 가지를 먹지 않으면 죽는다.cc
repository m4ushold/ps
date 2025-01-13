#include <bits/stdc++.h>
using namespace std;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    init(n);
    vector<tuple<int,int,int>> v(m);
    for(auto &[t,u,v]:v) cin >> u >> v >> t;
    sort(v.begin(),v.end());
    int a=1;
    for(auto [t,u,v]:v) {
        if(t>a) break;
        if(Union(u,v) && t==a) a++;
    }
    cout << a;
    return 0;
}