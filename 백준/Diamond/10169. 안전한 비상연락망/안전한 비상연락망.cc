#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll SZ=1<<17, INF=0x3f3f3f3f3f3f3f3f;
ll N, M, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], SP[SZ];
ll R[SZ];
vector<int> T[SZ], G[SZ];
vector<tuple<int,int,int,int>> E;

struct SegTree {
    ll T[SZ<<1], L[SZ<<1];
    void init() { for(int i=0;i<SZ*2;i++) T[i]=L[i]=INF; }
    void push(int node, int s, int e) {
        if(L[node]==INF) return;
        T[node]=min(T[node],L[node]);
        if(s!=e) for(int i:{node*2,node*2+1}) L[i]=min(L[i],L[node]);
        L[node]=INF;
    }
    void upd(int l, int r, ll v, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=min(T[node*2],T[node*2+1]);
    }
    ll qry(int l, int r, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return INF;
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return min(qry(l,r,2*node,s,m),qry(l,r,2*node+1,m+1,e));
    }
} seg;

void DFS0(int v=1, int p=-1){
    for(auto i:G[v]) if(p!=i) D[i]=D[v]+1, P[i]=v, DFS0(i,v), T[v].push_back(i);
}

void DFS1(int v){
    S[v] = 1;
    for(auto &i : T[v]){
        DFS1(i); S[v] += S[i];
        if(S[i] > S[T[v][0]]) swap(i, T[v][0]);
    }
}   

void DFS2(int v){
    static int pv = 0; IN[v] = ++pv;
    for(auto i : T[v]) TOP[i] = i == T[v][0] ? TOP[v] : i, DFS2(i);
}

void upd(int u, int v, ll w) { 
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        seg.upd(IN[TOP[u]], IN[u], w);
    }
    if(IN[u] > IN[v]) swap(u, v);
    seg.upd(IN[u]+1, IN[v], w);
}

ll qry(int u, int v){
    ll res = INF;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res = min(res,seg.qry(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = min(res,seg.qry(IN[u]+1, IN[v]));
    return res;
}

void Init(int n) { for(int i=1;i<=n;i++) SP[i]=i;}
int Find(int v) { return SP[v]==v? v: SP[v]=Find(SP[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (SP[SP[u]]=SP[v], true); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(ll i=0,s,e,w;i<M;i++) {
        cin >> s >> e >> w;
        E.push_back({w,s,e,i+1});
    }
    
    Init(N), sort(E.begin(),E.end());
    ll mst=0;
    vector<tuple<int,int,int,int>> in, ex;
    for(auto [w,u,v,i]:E) {
        if(Union(u,v)) mst+=w, in.push_back({w,u,v,i}), G[u].push_back(v), G[v].push_back(u);
        else ex.push_back({w,u,v,i});
    }

    if(in.size() != N-1) {
        for(int i=0;i<M;i++) cout << "-1\n";
        return 0;
    }
    DFS0(1), DFS1(1), DFS2(TOP[1]=1);

    seg.init();
    for(auto [w,u,v,i]:ex) upd(u,v,w), R[i]=mst;

    for(auto [w,u,v,i]:in) {
        ll a = qry(u,v);
        R[i] = a==INF ? -1 : mst-w+a;
    }

    for(int i=1;i<=M;i++) cout << R[i] << '\n';
    return 0;
}