#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, vi[10101], P[10101];
vector<tuple<ll,ll,ll>> E;

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

ll kruskal()
{
    ll ret=0;
    Init(N);
    sort(E.begin(),E.end(),greater<>());
    for(auto [w,u,v]:E) if (Union(u,v)) ret+=w;
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e,w;i<M;i++) cin >> s >> e >> w, E.emplace_back(w,s,e);
    
    ll cnt=0, res=kruskal();
    for(int i=1;i<=N;i++) if(i==P[i]) cnt++;
    if(cnt>1) cout << -1;
    else cout << res;
    return 0;
}