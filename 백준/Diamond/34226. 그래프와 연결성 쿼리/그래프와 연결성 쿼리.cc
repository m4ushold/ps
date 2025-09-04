#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
constexpr int sz = 1<<17;
ll N, B, M, Q, R[sz], P[sz], S[sz], T;
vector<pair<ll,ll>> H;
pair<int,int> E[sz];
 
int Find(int v) {
    if(v==P[v]) return v;
    return Find(P[v]);
}
 
ll f(ll x) {return x*(x-1)/2;}
 
int Union(int u, int v) {
    if((u=Find(u)) == (v=Find(v))) return 0;
    if(S[u]>S[v]) swap(u,v);
    H.push_back({u,T});
    T = T - f(S[v]) - f(S[u]) + f(S[v]+S[u]);
    P[u]=v, S[v]+=S[u];
    return 1;
}
 
void Undo(int s) {
    while(H.size() > s) {
        auto [u,t] = H.back(); H.pop_back();
        S[P[u]]-=S[u], P[u]=u, T=t;
    }
}
 
struct Qry { int i, s, e; };
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> Q, B=500;
    for(int i=1;i<=N;i++) P[i]=i, S[i]=1;
    for(int i=1;i<=M;i++) cin >> E[i].first >> E[i].second;
 
    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end(),[&](Qry a, Qry b) {
        if(a.s/B == b.s/B) return a.e < b.e;
        return a.s < b.s;
    });
 
    int s=1, e=0, prev=-1;
    for(auto [i,l,r]:qry) {
        s = (l/B+1)*B;
        if(prev != l/B) Undo(0), e=s-1;
 
        if(r < s) {
            for(int i=l;i<=r;i++) Union(E[i].first, E[i].second);
            R[i] = T;
            Undo(0);
            continue;
        }
 
        while(e < r) ++e, Union(E[e].first, E[e].second);
        int tmp = H.size();
        while(l < s) --s, Union(E[s].first, E[s].second);
        R[i] = T, Undo(tmp), prev = l/B;
    }
    
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}