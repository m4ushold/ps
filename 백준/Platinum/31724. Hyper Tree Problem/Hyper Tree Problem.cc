#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, Q, P[20][303030], S[20][303030];
vector<tuple<int,int,int>> E;

int Find(int i, int v) { return P[i][v]==v?v:P[i][v]=Find(i,P[i][v]); }
void Union(int i, int u, int v) {
    u=Find(i, u),v=Find(i, v);
    if(u==v) return;
    if(S[u]>S[v]) swap(u,v);
    P[i][u]=v; S[i][v]+=S[i][u];
}

void merge(int u, int v, int w) {
    for(int i=0;i<20;i++) if(~(w>>i)&1) Union(i,u,v);
}

void upd(int e, int v) {
    auto &[a,b,w]=E[e];
    merge(a,b,w&=v);
}

ll qry(int n) {
    ll res=0;
    for(int i=0;i<20;i++) res+=(N-S[i][Find(i,n)])*(1LL<<i);
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    E.resize(N-1);
    for(int i=0;i<20;i++) for(int j=1;j<=N;j++) P[i][j]=j, S[i][j]=1;
    for(auto &[a,b,c]:E) cin >> a >> b >> c, merge(a,b,c);
    
    for(int i=0,q,e,v,n;i<Q;i++) {
        cin >> q;
        if(q&1) cin >> e >> v, upd(e-1,v);
        else cin >> n, cout << qry(n) << '\n';
    }
    return 0;
}