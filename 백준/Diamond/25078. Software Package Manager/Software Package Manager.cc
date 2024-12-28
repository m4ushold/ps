#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
struct LazySeg {
    ll T[sz<<1], L[sz<<1];
    LazySeg() {for(int i=0;i<sz*2;i++) L[i]=-1;}
    ll& operator[](int i) {return T[sz|i];}
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=(T[i*2]+T[i*2+1]); }
    void prop(int i, int s, int e) {
        if(L[i]<0) return;
        T[i]=(e-s+1)*L[i];
        if(s!=e) L[i*2]=L[i], L[i*2+1]=L[i];
        L[i]=-1;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=(T[i*2]+T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return (qry(l,r,i*2,s,m)+qry(l,r,i*2+1,m+1,e));
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
    void update(int u, int v, int x) {
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            seg.upd(IN[TOP[u]], IN[u], x);
        }
        if(IN[u] > IN[v]) swap(u,v);
        seg.upd(IN[u], IN[v], x);
    }
    ll query(int u, int v) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=seg.qry(IN[TOP[u]], IN[u]);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=seg.qry(IN[u], IN[v]);
        return res;
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1,p;i<n;i++) cin >> p, tree.connect(i+1,p+1);
    tree.build();

    int q; cin >> q;
    for(int i=0,x;i<q;i++) {
        string op; cin >> op >> x;
        ++x;
        if(op == "install") {
            cout << tree.D[x]-tree.query(x, 1)+1 << '\n';
            tree.update(x, 1, 1);
        } else {
            cout << seg.qry(tree.IN[x], tree.OUT[x]) << '\n';
            seg.upd(tree.IN[x], tree.OUT[x], 0);
        }

    }
    return 0;
}