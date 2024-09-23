#include <bits/stdc++.h>
using namespace std;

const int SZ=1<<17;
int N, M, P[11][SZ], R[11][SZ];
pair<int,int> Q[SZ];
vector<tuple<int,int,int>> T[SZ<<1], OP;
map<pair<int,int>,int> E, V;

int Find(int i, int v) {
    if(v==P[i][v]) return v;
    return Find(i,P[i][v]);
}

int Union(int i, int u, int v) {
    u=Find(i,u), v=Find(i,v);
    if(u==v) return 0;
    if(R[i][u]>R[i][v]) swap(u,v);
    P[i][u]=v;
    
    if(R[i][u]==R[i][v]) R[i][v]++, OP.push_back({i,u,1});
    else OP.push_back({i,u,0});
    return 1;
}

void Undo() {
    auto [i,u,f]=OP.back(); OP.pop_back();
    int v=P[i][u];
    if(f) R[i][v]--;
    P[i][u]=u;
}

void update(int i, int s, int e, int l, int r, tuple<int,int,int> v) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) { T[i].push_back(v); return; }
	int m=s+e>>1;
	update(i*2, s, m, l, r, v);
	update(i*2+1, m+1, e, l, r, v);
}

void dnc(int i, int s, int e) {
    int cnt=0, m=s+e>>1;
    for(auto [u,v,w]:T[i]) for(int j=w;j<10;j++) cnt+=Union(j,u,v);
    if(s==e) {
        if(Q[s].second) {
            int dap=1e9;
            for(int i=0;i<10;i++) if(Find(i,Q[s].first)==Find(i,Q[s].second)) dap=min(dap,i);
            if(dap<10) cout << dap << '\n';
            else cout << "-1\n";
        }
    } else dnc(i*2,s,m), dnc(i*2+1,m+1,e);
    while(cnt--) Undo();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1,a,b,c,d;i<=M;i++) {
        cin >> a >> b >> c;
        if(b>c) swap(b,c);
        if(a==0) E[{b,c}]=i, cin >> d, V[{b,c}]=d;
        else if(a==1) update(1,1,M,E[{b,c}],i,{b,c,V[{b,c}]}), E.erase({b,c});
        else Q[i]={b,c};
    }
    for(auto [i,j]:E) update(1,1,M,j,M,{i.first,i.second,V[i]});
    for(int i=0;i<10;i++) for(int j=1;j<=M;j++) P[i][j]=j, R[i][j]=1;
    dnc(1,1,M);
    return 0;
}