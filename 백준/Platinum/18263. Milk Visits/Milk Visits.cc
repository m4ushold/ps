#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<17;
struct Seg {
    vector<int> T[sz<<1];
    void build() { 
        for(int i=sz-1;i>=1;i--) {
            T[i].resize(T[i*2].size()+T[i*2+1].size());
            merge(T[i*2].begin(),T[i*2].end(), T[i*2+1].begin(),T[i*2+1].end(), T[i].begin());
        }
    }
    vector<int>& operator[](int i) {return T[sz|i];}
    ll query(int l, int r, int c) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=upper_bound(T[l].begin(),T[l].end(),c)-lower_bound(T[l].begin(),T[l].end(),c), l++;
            if(~r&1) ret+=upper_bound(T[r].begin(),T[r].end(),c)-lower_bound(T[r].begin(),T[r].end(),c), r--;
        }
        return r-l+1-ret;
    }
} seg;

struct HLD {
    int TOP[sz], P[sz], D[sz], SZ[sz], IN[sz];
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
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
    }
    ll query(int u, int v, int x) {
        ll res=0;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res+=seg.query(IN[TOP[u]], IN[u], x);
        }
        if(IN[u] > IN[v]) swap(u,v);
        res+=seg.query(IN[u], IN[v], x);
        return res;
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=1,a,b;i<n;i++) cin >> a >> b, tree.connect(a,b);
    tree.build();

    for(int i=1;i<=n;i++) seg[tree.IN[i]].push_back(v[i-1]);
    seg.build();

    for(int i=1,a,b,c;i<=m;i++) {
        cin >> a >> b >> c;
        cout << !!tree.query(a,b,c);
    }
    return 0;
}