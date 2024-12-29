#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;

int N, Q, P[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[u]=v, true); }

struct LazySeg {
    const static int sz=1<<17;
    ll T[sz<<1], L[sz<<1];
    LazySeg() {for(int i=0;i<sz*2;i++) L[i]=-1;}
    void prop(int i, int s, int e) {
        if(L[i]<0) return;
        T[i]=(e-s+1)*L[i];
        if(s!=e) L[i*2]=L[i], L[i*2+1]=L[i];
        L[i]=-1;
    }
    void update(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=v, prop(i,s,e); return;}
        int m=s+e>>1;
        update(l,r,v,i*2,s,m), update(l,r,v,i*2+1,m+1,e);
        T[i]=(T[i*2]+T[i*2+1]);
    }
    ll query(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return (query(l,r,i*2,s,m)+query(l,r,i*2+1,m+1,e));
    }
} seg;

struct HLD {
    int TOP[sz], P[sz], D[sz], SZ[sz], IN[sz], vi[sz];
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
        vi[v]=1;
        for(int i:G[v]) TOP[i]= (i==G[v][0] ? TOP[v] : i), d3(i);
    }
    void build() {
        for(int i=1;i<=N;i++) if(!vi[i]) {
            d1(i), d2(i), d3(TOP[i]=i);
        }
    }
    void update(int u, int v, int x) {
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            seg.update(IN[TOP[u]], IN[u], x);
        }
        if(IN[u] > IN[v]) swap(u,v);
        seg.update(IN[u]+1, IN[v], x);
    }
    ll query(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=seg.query(IN[TOP[u]], IN[u]);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=seg.query(IN[u]+1, IN[v]);
        return res;
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    init(N);
    vector<array<ll,3>> q(Q);
    for(auto &[op,u,v]:q) {
        cin >> op >> u >> v;
        if(op==1 && Union(u,v)) tree.connect(u,v);
    }
    tree.build(), init(N);

    for(auto [op,u,v]:q) {
        if(tree.D[u] > tree.D[v]) swap(u,v);

        if(op==1) {
            if(Union(u,v)) tree.update(v,tree.P[v],1);
            else tree.update(u,v,0);
        } else {
            if(Find(u)^Find(v)) cout << "-1\n";
            else cout << tree.query(u,v) << '\n';
        }
    }
    return 0;
}