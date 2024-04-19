#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll SZ=1<<17, INF=0x3f3f3f3f3f3f3f3f;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], SP[SZ], A[SZ], V[SZ];
vector<int> G[SZ], T[SZ];

ll m(ll a, ll b) { return a+b; }

struct SegTree {
    static const int sz=1<<17;
    ll T[sz<<1], L[sz<<1];
    void init() { for(int i=0;i<SZ*2;i++) T[i]=INF; }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=min(T[i*2],T[i*2+1]); }
    void push(int node, int s, int e) {
        if(L[node]==0) return;
        T[node]-=L[node];
        if(s!=e) L[node*2]+=L[node], L[node*2+1]+=L[node];
        L[node]=0;
    }
    void upd(int l, int r, int v, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=min(T[node*2],T[node*2+1]);
    }
    ll qry(int l, int r, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return INF;
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return min(qry(l,r,2*node,s,m),qry(l,r,2*node+1,m+1,e));
    }
} seg;

void DFS0(int v=1, int p=-1){
    V[v]=1;
    for(auto i:G[v]) if(p!=i) T[v].push_back(i), D[i]=D[v]+1, P[i]=v, DFS0(i,v);
}

void DFS1(int v=1){
    S[v] = 1;
    for(auto &i : T[v]){
        DFS1(i); S[v] += S[i];
        if(S[i] > S[T[v][0]]) swap(i, T[v][0]);
    }
}

void DFS2(int v=1){
    static int pv = 0; IN[v] = ++pv;
    for(auto i : T[v]) TOP[i] = i == T[v][0] ? TOP[v] : i, DFS2(i);
}

void upd(int u, int v, int w) {
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        seg.upd(IN[TOP[u]], IN[u],w);
    }
    if(IN[u] > IN[v]) swap(u, v);
    seg.upd(IN[u], IN[v],w);
}

ll qry(int u, int v){
    ll res = INF;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res = min(res,seg.qry(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = min(res,seg.qry(IN[u], IN[v]));
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    seg.init();
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    DFS0(), DFS1(), DFS2(TOP[1]=1);
    for(int i=1,a;i<=N;i++) cin >> a, seg.T[SZ|IN[i]]=a;
    seg.build();
    
    int cnt=0;
    for(int i=0,w,u,v;i<Q;i++) {
        cin >> u >> v >> w;
        if(qry(u,v)<w) break;
        upd(u,v,w), ++cnt;
    }
    cout << cnt;
    return 0;
}