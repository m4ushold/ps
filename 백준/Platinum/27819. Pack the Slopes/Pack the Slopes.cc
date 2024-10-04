#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<17, inf=LONG_LONG_MAX/4;
struct LazySeg {
    ll T[sz<<1], L[sz<<1];
    ll& operator[](int i) {return T[sz|i];}
    void clear() {
        memset(L, 0, sizeof(L));
        for(int i=0;i<sz;i++) T[i|sz]=inf;
    }
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=min(T[i*2],T[i*2+1]); }
    void prop(int i, int s, int e) {
        if(!L[i] || T[i]>=inf) return;
        T[i]+=L[i];
        if(s!=e) L[i*2]+=L[i], L[i*2+1]+=L[i];
        L[i]=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=min(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return inf;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return min(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} cap, cost;

struct HLD {
    int TOP[sz], P[sz], D[sz], SZ[sz], IN[sz], RIN[sz], pv;
    vector<int> GG[sz], G[sz];
    void clear() {
        pv=0;
        memset(TOP, 0, sizeof(TOP));
        memset(TOP, 0, sizeof(P));
        memset(TOP, 0, sizeof(D));
        cap.clear(), cost.clear();
        for(int i=0;i<sz;i++) G[i].clear(), GG[i].clear();
    }
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
        IN[v]=++pv, RIN[pv]=v;
        for(int i:G[v]) TOP[i]= (i==G[v][0] ? TOP[v] : i), d3(i);
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
    }
    void update(int u, int v, ll x) {
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            cap.upd(IN[TOP[u]], IN[u], x);
        }
        if(IN[u] > IN[v]) swap(u,v);
        cap.upd(IN[u]+1, IN[v], x);
    }
    ll query(int u, int v) {
        ll res=inf;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res=min(res,cap.qry(IN[TOP[u]], IN[u]));
        }
        if(IN[u] > IN[v]) swap(u,v);
        res=min(res,cap.qry(IN[u]+1, IN[v])); // if edge use IN[u]+1 instead of IN[u]
        if(res>=inf) return 0LL;
        return res;
    }
    void updateCost(int v, ll x) {
        cost.upd(IN[v], IN[v], x);
    }
    pair<ll,ll> minCost() {
        int i=1;
        while(i<sz) {
            if(cost.T[i*2]<cost.T[i*2+1]) i*=2;
            else i=i*2+1;
        }
        return {cost.T[1],RIN[sz^i]};
    }
    void dfs(int v=1) {
        for(int i:G[v]) {
            cost[IN[i]] += cost[IN[v]];
            dfs(i);
        }
    }
    void setValue(vector<tuple<int,int,int,int>> &edges) {
        for(auto [u,v,s,c]:edges) {
            int a=IN[D[u]>D[v] ? u : v];
            cap[a]=s, cost[a]=c;
        }
        cost[1]=0;
        dfs();
        cost[1]=inf;
        cap.bld(), cost.bld();
    }
} tree;

void sol(int tc) {
    tree.clear();
    int n; cin >> n;
    vector<tuple<int,int,int,int>> edges(n-1);
    
    ll tot = 0;
    for(auto &[u,v,s,c]:edges) {
        cin >> u >> v >> s >> c;
        if(u==1 || v==1) tot+=s;
        tree.connect(u,v);
    }
    
    tree.build();
    tree.setValue(edges);

    ll dap=0;
    for(int i=1;i<n;i++) {
        auto [x,u] = tree.minCost();
        ll y = tree.query(1,u);
        dap+=x*y;
        tree.update(1,u,-y);
        tree.updateCost(u,inf);
    }
    cout << "Case #" << tc << ": " << tot << ' ' << dap << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}