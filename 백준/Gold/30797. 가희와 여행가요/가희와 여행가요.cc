#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll N, M, vi[202020], D[202020], P[202020], T;
vector<tuple<ll,ll,ll,ll>> E;

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

ll kruskal()
{
    ll ret=0;
    Init(N);
    sort(E.begin(),E.end());
    for(auto [w,t,u,v]:E) if(Union(u,v)) ret+=w, T=max(T,t);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e,w,t;i<M;i++) cin >> s >> e >> w >> t, E.emplace_back(w,t,s,e);
    ll res=kruskal(), cnt=0;
    for(int i=1;i<=N;i++) if(i==P[i]) cnt++;
    if(cnt>1) cout << -1;
    else cout << T << ' ' << res;
    return 0;
}