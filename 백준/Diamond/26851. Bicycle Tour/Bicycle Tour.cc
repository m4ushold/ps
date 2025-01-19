#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<17, inf=LLONG_MAX/8;

struct Seg {
    ll T[sz<<1], L[sz<<1];
    Seg() {for(int i=1;i<sz*2;i++) T[i]=L[i]=inf;}
    void prop(int i, int s, int e) {
        if(L[i]==inf) return;
        T[i]=min(T[i], L[i]);
        if(s!=e) for(int j:{i*2,i*2+1}) L[j]=min(L[j], L[i]);
        L[i]=inf;
    }
    void update(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=v, prop(i,s,e); return;}
        int m=s+e>>1;
        update(l,r,v,i*2,s,m), update(l,r,v,i*2+1,m+1,e);
        T[i]=min(T[i*2],T[i*2+1]);
    }
    ll query(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return inf;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return min(query(l,r,i*2,s,m),query(l,r,i*2+1,m+1,e));
    }
    ll operator[](int i) {return query(i,i);}
} seg;

struct HLD {
    ll TOP[sz], P[18][sz], D[sz], SZ[sz], IN[sz], W[18][sz];
    vector<pair<int,int>> GG[sz];
    vector<int> G[sz];
    void connect(int u, int v, int w) {
        GG[u].push_back({v,w}), GG[v].push_back({u,w});
    }
    void d1(int v=1, int p=-1) {
        for(auto [i,w]:GG[v]) if(i!=p) {
            G[v].push_back(i), D[i]=D[v]+1, P[0][i]=v, W[0][i]=w, d1(i,v);
        }
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
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
        for(int i=1;i<18;i++) for(int j=1;j<sz;j++) P[i][j]=P[i-1][P[i-1][j]], W[i][j]=max(W[i-1][j], W[i-1][P[i-1][j]]);
    }
    void update(int u, int v, ll x) {
        for(;TOP[u]!=TOP[v];u=P[0][TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            seg.update(IN[TOP[u]], IN[u], x);
        }
        if(IN[u] > IN[v]) swap(u,v);
        seg.update(IN[u], IN[v], x); // if edge use IN[u]+1 instead of IN[u]
    }

    ll mx(int u, int v) {
        if(D[u]<D[v]) swap(u,v);
        ll diff=D[u]-D[v], res=0;
        for(int i=0;diff;i++,diff>>=1) if(diff&1) res=max(res, W[i][u]), u=P[i][u];
        if(u==v) return res;
        for(int i=18;i>=0;i--) if(P[i][u]!=P[i][v]) res=max({res,W[i][u],W[i][v]}), u=P[i][u], v=P[i][v];
        return max(res, W[0][u]);
    }
} tree;

int N, M, S[sz], H[sz];
void init(int n) { for(int i=1;i<=n;i++) S[i]=i; }
int Find(int v) { return S[v]==v?v:S[v]=Find(S[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]=v, 1); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> H[i];
    init(N);
    vector<array<ll,3>> edge, ex;
    for(int i=1,u,v;i<=M;i++) {
        cin >> u >> v;
        edge.push_back({abs(H[u]-H[v]),u,v});
    }
    sort(edge.begin(),edge.end());
    for(auto [w,u,v]:edge) {
        if(Union(u,v)) tree.connect(u,v,w);
        else ex.push_back({w,u,v});
    }
    tree.build();
    for(auto [w,u,v]:ex) {
        ll a=tree.mx(u,v), b=w;
        tree.update(u,v,max(a,b));
    }

    for(int i=1;i<=N;i++) {
        ll ans=seg[tree.IN[i]];
        if(ans >= inf) ans=-1;
        cout << ans << ' ';
    }
    return 0;
}