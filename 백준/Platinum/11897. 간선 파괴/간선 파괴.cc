#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<int> ll,rr;
    vector<pll> e;
    init(n);
    for(int i=0;i<m;i++) {
        int u,v; cin >> u >> v;
        e.push_back({u,v});
        if(Union(u,v)) ll.push_back(i);
    }
    ll.push_back(m+1);

    init(n);
    for(int i=m-1;i>=0;i--) {
        auto [u,v] = e[i];
        if(Union(u,v)) rr.push_back(i);
    }
    rr.push_back(-1);

    int q; cin >> q;
    for(int i=0;i<q;i++) {
        int l,r; cin >> l >> r;
        init(n);
        for(int j=0;ll[j]<l-1;j++) {
            auto [u,v]=e[ll[j]];
            Union(u,v);
        }
        for(int j=0;rr[j]>=r;j++) {
            auto [u,v]=e[rr[j]];
            Union(u,v);
        }

        int cnt=0;
        for(int j=1;j<=n;j++) if(P[j] == j) cnt++;
        cout << cnt << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}