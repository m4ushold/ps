#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17;
ll N, Q, P[sz], S[sz], R[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    init(N);
    vector<array<ll,3>> edges(N-1), qry(Q);
    for(auto &[w,u,v]:edges) cin >> u >> v >> w;
    sort(edges.begin(),edges.end());
    for(int i=0;i<Q;i++) cin >> qry[i][0] >> qry[i][1], qry[i][2]=i;
    sort(qry.begin(),qry.end(),greater<>());

    for(auto [k,v,idx]:qry) {
        while(edges.size() && edges.back()[0] >= k) {
            auto [a,b,c] = edges.back();
            Union(b,c), edges.pop_back();
        }
        R[idx] = S[Find(v)]-1;
    }
    for(int i=0;i<Q;i++) cout << R[i] << '\n';
    return 0;
}