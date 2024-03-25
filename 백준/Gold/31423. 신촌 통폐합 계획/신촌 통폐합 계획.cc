#include <bits/stdc++.h>
using namespace std;

int P[505050];
vector<int> G[505050];
string V[505050];
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

void f(int v) {
    cout << V[v];
    for(int i:G[v]) f(i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> V[i];
    Init(n);
    int r;
    for(int i=1,s,e;i<n;i++) {
        cin >> s >> e, G[Find(s)].push_back(e);
        Union(s,e), r=s;
    }
    f(r);
    return 0;
}