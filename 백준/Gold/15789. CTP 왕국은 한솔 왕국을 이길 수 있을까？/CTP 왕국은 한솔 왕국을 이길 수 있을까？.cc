#include <bits/stdc++.h>
using namespace std;

int P[101010], S[101010];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) { return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    init(n);
    for(int i=0,u,v;i<m;i++) cin >> u >> v, Union(u,v);
    int c,h,k; cin >> c >> h >> k;
    int dap=S[Find(c)];

    vector<int> v;
    for(int i=1;i<=n;i++) if(i==P[i] && i!=Find(c) && i!=Find(h)) v.push_back(S[i]);
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<min(k,(int)v.size());i++) dap+=v[i];
    cout << dap;
    return 0;
}