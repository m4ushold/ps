#include <bits/stdc++.h>
using namespace std;

const int SZ=1<<17;
int N, M, P[SZ], R[SZ];
pair<int,int> Q[SZ];
vector<pair<int,int>> OP, T[SZ<<1];
map<pair<int,int>,int> E;

int Find(int v) {
    if(v==P[v]) return v;
    return Find(P[v]);
}

int Union(int u, int v) {
    u=Find(u), v=Find(v);
    if(u==v) return 0;
    if(R[u]>R[v]) swap(u,v);
    P[u]=v;
    OP.push_back({u,0});
    if(R[u]==R[v]) R[v]++, OP.back().second=1;
    return 1;
}

void Undo() {
    auto [u,f]=OP.back(); OP.pop_back();
    int v=P[u];
    if(f) R[v]--;
    P[u]=u;
}

void update(int i, int s, int e, int l, int r, pair<int,int> v) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) { T[i].push_back(v); return; }
	int m=s+e>>1;
	update(i*2, s, m, l, r, v);
	update(i*2+1, m+1, e, l, r, v);
}

void dnc(int i, int l, int r) {
    int cnt=0, m=l+r>>1;
    for(auto [u,v]:T[i]) cnt+=Union(u,v);
    if(l==r) {
        if(Q[l].second) cout << (Find(Q[l].first) == Find(Q[l].second) ? "YES" : "NO") << '\n';
    } else dnc(i*2,l,m), dnc(i*2+1,m+1,r);
    while(cnt--) Undo();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=M;i++) P[i]=i, R[i]=1;
    for(int i=1,a,b,c;i<=M;i++) {
        cin >> a >> b >> c;
        if(b>c) swap(b,c);
        if(a==1) E[{b,c}]=i;
        else if(a==2) update(1,1,M,E[{b,c}], i, {b,c}), E.erase({b,c});
        else Q[i]={b,c};
    }
    for(auto [i,j]:E) update(1,1,M,j,M,i);
    dnc(1,1,M);
    return 0;
}