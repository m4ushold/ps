#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, P[10101], U, V;
vector<tuple<ll,ll,ll>> E;

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

ll kruskal()
{
    ll ret=1e9;
    Init(N);
    sort(E.begin(),E.end(),greater<>());
    for(auto [w,u,v]:E) {
        if(Union(u,v)) ret=min(ret,w);
        if(Find(U) == Find(V)) break;
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e,w,t;i<M;i++) cin >> s >> e >> w, E.emplace_back(w,s,e);
    cin >> U >> V;
    cout << kruskal();
    return 0;
}