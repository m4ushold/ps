#include <bits/stdc++.h>
using namespace std;

int P[101010], S[101010], A[101010];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], A[v]+=A[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,q; cin >> n >> m >> q;
    init(n);
    for(int i=1;i<=n;i++) cin >> A[i];
    for(int i=0,u,v;i<m;i++) cin >> u >> v, Union(u,v);
    for(int i=0,x;i<q;i++) {
        cin >> x;
        x=Find(x);
        cout << (A[x] > S[x]-A[x]) << '\n';
    }
    return 0;
}