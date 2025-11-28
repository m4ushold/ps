#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int P[202020], S[202020], F[202020];
vector<int> G[202020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    int n,m; cin >> n >> m;
    init(n);
    for(int i=1;i<=m;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    vector<int> v(n);
    for(int &i:v) cin >> i;
    reverse(all(v));
    vector<bool> a;
    a.push_back(0);
    for(int i=0;i<n;i++) {
        int x = v[i];
        F[x]=1;
        for(int j:G[x]) if(F[j]) Union(x,j);
        a.push_back(S[Find(x)] == i+1);
    }
    reverse(all(a));
    for(bool i:a) cout << (i?"CONNECT":"DISCONNECT") << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}