#include <bits/stdc++.h>
using namespace std;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) { return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
void War(int u, int v) {
    u=Find(u), v=Find(v);
    if(u==v) return;

    if(S[u] == S[v]) S[u]=S[v]=0, Union(u,v);
    else if(S[u] > S[v]) S[u]-=S[v], P[v]=u;
    else S[v]-=S[u], P[u]=v;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> S[i];
    init(n);

    for(int i=0,o,p,q;i<m;i++) {
        cin >> o >> p >> q;
        if(o==1) Union(p,q);
        else War(p,q);
    }

    vector<int> v;
    for(int i=1;i<=n;i++) if(i==P[i] && S[i]) v.push_back(S[i]);
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int i:v) cout << i << ' ';
    return 0;
}