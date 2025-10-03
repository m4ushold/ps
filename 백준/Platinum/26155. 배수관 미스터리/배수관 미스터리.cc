#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, Q, P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    cin >> N >> M;
    vector<tuple<double,int,int>> e(M);
    for(auto &[w,u,v]:e) cin >> u >> v >> w;
    sort(e.rbegin(),e.rend());
    init(N);
    int x = N;
    vector<pair<double,int>> r;
    r.push_back({1,N});
    for(auto [w,u,v]:e) if(Union(u,v)) r.push_back({w,--x});
    reverse(r.begin(),r.end());

    cin >> Q;
    for(int i=0;i<Q;i++) {
        double x; cin >> x;
        auto y = *lower_bound(r.begin(),r.end(),pair<double,int>(x,0));
        cout << y.second << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}