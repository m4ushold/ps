#include <bits/stdc++.h>
using namespace std;

int P[1010101], G[1010101];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[u]=v, true); }

void sol() {
    int n; cin >> n;
    init(n);
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++) {
        int g,d; cin >> g >> d;
        pq.push({g-d,i});
        G[i]=g-d;
    }
    while(pq.size() > 1) {
        auto [g,i] = pq.top(); pq.pop();
        i = Find(i);
        int j=Find(i==n?1:i+1);
        if(Find(i) == Find(j)) continue;
        if(G[i] != g) continue;
        
        i=Find(i), j=Find(j);
        Union(i,j);
        G[Find(j)]+=g;
        pq.push({G[Find(j)],Find(j)});
    }
    int l=Find(1);
    if(G[l]<0) cout << "IMPOSSIBLE\n";
    else cout << (l==n?1:l+1) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}