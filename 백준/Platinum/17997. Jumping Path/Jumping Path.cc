#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<20, mod = 11092019;
struct SegTree {
    pair<ll,ll> T[1<<21];
    pair<ll,ll> mxx(pair<ll,ll> a, pair<ll,ll> b) {
        if(a.first==b.first) return {a.first, (a.second+b.second)%mod};
        else if(a.first > b.first) return a;
        else return b;
    }
    void update(ll v, pair<ll,ll> vv) {
        v|=sz, T[v]=mxx(T[v],vv);
        while(v>>=1) T[v]=mxx(T[v*2],T[v*2+1]);
    }
    pair<ll,ll> query(ll l, ll r) {
        pair<ll,ll> res;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=mxx(res,T[l++]);
            if(~r&1) res=mxx(res,T[r--]);
        }
        return res;
    }
} seg;

struct HLD {
    ll TOP[sz], P[sz], D[sz], SZ[sz], IN[sz];
    vector<ll> GG[sz], G[sz];
    void connect(ll u, ll v) {
        GG[u].push_back(v), GG[v].push_back(u);
    }
    void d1(ll v=1, ll p=-1) {
        for(ll i:GG[v]) if(i!=p) G[v].push_back(i), D[i]=D[v]+1, P[i]=v, d1(i,v);
    }
    void d2(ll v=1) {
        SZ[v]=1;
        for(ll &i:G[v]) {
            d2(i), SZ[v]+=SZ[i];
            if(SZ[i]>SZ[G[v][0]]) swap(i,G[v][0]);
        }
    }
    void d3(ll v) {
        static ll pv=0; IN[v]=++pv;
        for(ll i:G[v]) TOP[i]= (i==G[v][0] ? TOP[v] : i), d3(i);
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
    }
    void update(ll v, pair<ll,ll> x) {
        seg.update(IN[v], x);
    }
    pair<ll,ll> query(ll u, ll v) {
        pair<ll,ll> res;
        for(;TOP[u]!=TOP[v];u=P[TOP[u]]) {
            if(D[TOP[u]] < D[TOP[v]]) swap(u,v);
            res=seg.mxx(res,seg.query(IN[TOP[u]], IN[u]));
        }
        if(IN[u] > IN[v]) swap(u,v);
        res=seg.mxx(res,seg.query(IN[u], IN[v]));
        return res;
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i=1,x;i<=n;i++) {
        cin >> x;
        v.push_back({x,i});
    }
    for(ll i=2,p;i<=n;i++) {
        cin >> p;
        tree.connect(i,p);
    }
    tree.build();
    sort(v.begin(),v.end(),[](pair<ll,ll> a, pair<ll,ll> b){
        if(a.first == b.first) return tree.IN[a.second] < tree.IN[b.second];
        return a.first < b.first;
    });

    pair<ll,ll> ans;
    for(auto [x,i]:v) {
        auto [mx, cnt] = tree.query(1,i);
        ans = seg.mxx(ans, {mx+1,cnt?cnt:1});
        tree.update(i, {mx+1, cnt ? cnt : 1});
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
}