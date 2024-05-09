#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using node_t=tuple<ll,ll,ll,ll>; // l, tot, max, r

constexpr ll SZ=1<<18, INF=LONG_LONG_MAX/8;
const node_t id={INF,INF,INF,INF};
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], A[SZ];
vector<int> T[SZ], G[SZ];


node_t max(const node_t& a, const node_t& b) {
    if(a==id) return b;
    if(b==id) return a;
    auto [al,aa,am,ar]=a;
    auto [bl,bb,bm,br]=b;
    return {max(al,aa+bl),aa+bb,max({am,bm,ar+bl}),max(br,ar+bb)};
}

struct SegTree {
    ll L[SZ<<1];
    node_t T[SZ<<1];
    void init() { for(int i=0;i<SZ*2;i++) L[i]=INF; }
    void build() { for(int i=SZ-1;i>=1;i--) T[i]=max(T[i*2],T[i*2+1]); }
    void push(int node, int s, int e) {
        if(L[node]==INF) return;
        int t=(e-s+1)*L[node];
        if(L[node]<0) T[node]={L[node],t,L[node],L[node]};
        else T[node]={t,t,t,t};
        if(s!=e) L[node*2]=L[node], L[node*2+1]=L[node];
        L[node]=INF;
    }
    void upd(int l, int r, int v, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=max(T[node*2],T[node*2+1]);
    }
    node_t qry(int l, int r, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s||e<l) return id;
        if(l<=s&&e<=r) return T[node];
        int m=(s+e)/2;
        return max(qry(l,r,node*2,s,m),qry(l,r,node*2+1,m+1,e));
    }
} seg;

void DFS0(int v, int p=-1){ for(auto i : G[v]) if(p!=i) D[i]=D[v]+1, P[i]=v, DFS0(i,v), T[v].push_back(i); }

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

void upd(int u, int v, ll w){
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        seg.upd(IN[TOP[u]], IN[u], w);
    }
    if(IN[u] > IN[v]) swap(u, v);
    seg.upd(IN[u], IN[v], w);
}

node_t rev(node_t x) {
    auto [a,b,c,d]=x;
    return {d,b,c,a};
}

ll qry(int u, int v){
    node_t a=id,b=id;
    if(IN[u] > IN[v]) swap(u,v);
    while(TOP[u]!=TOP[v]) {
        if(D[TOP[u]] >   D[TOP[v]]) {
            a=max(seg.qry(IN[TOP[u]],IN[u]),a);
            u=P[TOP[u]];
        } else {
            b=max(seg.qry(IN[TOP[v]],IN[v]),b);
            v=P[TOP[v]];
        }
    }
    if(IN[u] > IN[v]) a=max(seg.qry(IN[v],IN[u]),a);
    else b=max(seg.qry(IN[u],IN[v]),b);
    a=max(rev(a),b);
    auto [c,d,e,f]=a;
    return max({c,d,e,f});
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    DFS0(1); DFS1(1); DFS2(TOP[1]=1);
    seg.init();
    for(int i=1;i<=N;i++) seg.T[SZ|IN[i]]={A[i],A[i],A[i],A[i]};
    seg.build();

    for(ll i=0,a,u,v,w;i<Q;i++) {
        cin >> a >> u >> v >> w;
        if(a&1) upd(u,v,w);
        else cout << qry(u,v) << '\n';
    }
    return 0;
}