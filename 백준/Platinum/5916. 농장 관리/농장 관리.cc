#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<17;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ];
vector<int> G[SZ], T[SZ];

ll merge(ll a, ll b) { return a+b; }

struct SegTree {
    ll T[SZ<<1], L[SZ<<1];
    void build() { for(int i=SZ-1;i>=1;i--) T[i]=merge(T[i*2],T[i*2+1]); }
    void push(int node, int s, int e) {
        if(L[node]==0) return;
        T[node]+=(e-s+1)*L[node];
        if(s!=e) L[node*2]+=L[node], L[node*2+1]+=L[node];
        L[node]=0;
    }
    void upd(int l, int r, int v, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=merge(T[node*2],T[node*2+1]);
    }
    ll qry(int l, int r, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return merge(qry(l,r,2*node,s,m),qry(l,r,2*node+1,m+1,e));
    }
} seg;

struct HLD {
    void f(int v=1, int p=-1){
        for(auto i:G[v]) if(p!=i) T[v].push_back(i), D[i]=D[v]+1, P[i]=v, f(i,v);
    }
    void g(int v=1){
        S[v] = 1;
        for(auto &i : T[v]){
            g(i); S[v] += S[i];
            if(S[i] > S[T[v][0]]) swap(i, T[v][0]);
        }
    }
    void h(int v) {
        static int pv = 0; IN[v] = ++pv;
        for(auto i : T[v]) TOP[i] = i == T[v][0] ? TOP[v] : i, h(i);
    }
    void build() { f(), g(), h(TOP[1]=1); }

    void upd(int u, int v, int x) {
        for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
            if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
            seg.upd(IN[TOP[u]], IN[u], x);
        }
        if(IN[u] > IN[v]) swap(u, v);
        seg.upd(IN[u]+1, IN[v], x);
    }
    ll qry(int u, int v){
        ll res = 0;
        for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
            if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
            res = merge(res,seg.qry(IN[TOP[u]], IN[u]));
        }
        if(IN[u] > IN[v]) swap(u, v);
        res = merge(res,seg.qry(IN[u]+1, IN[v]));
        return res;
    }
} tree;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    tree.build();

    for(int i=0,u,v;i<Q;i++) {
        char w; cin >> w >> u >> v;
        if(w=='P') tree.upd(u,v,1);
        else cout << tree.qry(u,v) << '\n';
    }
    return 0;
}