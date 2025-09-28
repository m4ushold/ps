#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, A[101010];
vector<int> G[101010];

int P[101010], S[101010];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    cin >> N;
    init(N);
    vector<pll> v(N);
    for(int i=1;i<=N;i++) {
        int x; cin >> x;
        v.push_back({x,i});
    }
    sort(v.rbegin(),v.rend());
    for(int i=1;i<N;i++) {
        int u,v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    ll cnt=0, mx=0;
    for(auto [x,u]:v) {
        A[u]=1;
        for(int j:G[u]) if(A[j]) Union(u,j);
        mx=max(mx,S[Find(u)]*x);
    }
    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}