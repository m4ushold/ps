#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<19, inf=1e10;

struct LazySeg {
    ll T[sz<<1], L[sz<<1], M[sz<<1];
    LazySeg() {
        for(int i=1;i<sz<<1;i++) L[i]=inf, M[i]=-inf;
    }
    void prop(int i, int s, int e) {
        if(L[i] == inf) return;
        T[i]=(e-s+1)*L[i];
        M[i]=L[i];
        if(s!=e) L[i*2]=L[i], L[i*2+1]=L[i];
        L[i]=inf;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=(T[i<<1]+T[i<<1|1]);
        M[i]=max(M[i<<1],M[i<<1|1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return (qry(l,r,i*2,s,m)+qry(l,r,i*2+1,m+1,e));
    }
    ll mx(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return -inf;
        else if(l<=s && e<=r) return M[i];
        int m=s+e>>1;
        return max(mx(l,r,i*2,s,m),mx(l,r,i*2+1,m+1,e));
    }
} seg;

struct HLD {
    int TOP[sz], P[sz], D[sz], SZ[sz], IN[sz], OUT[sz];
    vector<int> GG[sz], G[sz];
    void connect(int u, int v) {
        GG[u].push_back(v), GG[v].push_back(u);
    }
    void d1(int v=1, int p=-1) {
        for(int i:GG[v]) if(i!=p) G[v].push_back(i), D[i]=D[v]+1, P[i]=v, d1(i,v);
    }
    void d2(int v=1) {
        SZ[v]=1;
        for(int &i:G[v]) {
            d2(i), SZ[v]+=SZ[i];
            if(SZ[i]>SZ[G[v][0]]) swap(i,G[v][0]);
        }
    }
    void d3(int v) {
        static int pv=0; IN[v]=++pv;
        for(int i:G[v]) TOP[i]= (i==G[v][0] ? TOP[v] : i), d3(i);
        OUT[v]=pv;
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
    }
    ll qry(int u, int v) {
        ll res=LLONG_MIN;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res=max(res,seg.mx(IN[TOP[u]], IN[u]));
        }
        if(IN[u] > IN[v]) swap(u,v);
        res=max(res,seg.mx(IN[u], IN[v]));
        return res;
    }
} tree;

ll N, Q, A[sz];

void sol(int tc) {
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<N;i++) {
        int u,v; cin >> u >> v;
        tree.connect(u,v);
    }
    tree.build();
    for(int i=1;i<=N;i++) seg.upd(tree.IN[i], tree.IN[i], A[i]);

    for(int i=0;i<Q;i++) {
        int op,x; cin >> op >> x;
        if(op==1) seg.upd(tree.IN[x], tree.OUT[x], tree.qry(1,tree.P[x]));
        else cout << seg.qry(tree.IN[x], tree.OUT[x]) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}