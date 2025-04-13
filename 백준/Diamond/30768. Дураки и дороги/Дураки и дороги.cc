#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll SZ=1<<19;
ll N, M, K, P[SZ], R[SZ];
pair<ll,ll> Q[SZ];
vector<pair<ll,ll>> OP, T[SZ<<1];
map<pair<ll,ll>,ll> E;

ll Find(ll v) {
    if(v==P[v]) return v;
    return Find(P[v]);
}

ll Union(ll u, ll v) {
    u=Find(u), v=Find(v);
    if(u==v) return 0;
    if(R[u]>R[v]) swap(u,v);
    P[u]=v;
    OP.push_back({u,0});
    if(R[u]==R[v]) R[v]++, OP.back().second=1;
    return 1;
}

void Undo() {
    auto [u,f]=OP.back(); OP.pop_back();
    ll v=P[u];
    if(f) R[v]--;
    P[u]=u;
}

void update(ll i, ll s, ll e, ll l, ll r, pair<ll,ll> v) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) { T[i].push_back(v); return; }
	ll m=s+e>>1;
	update(i*2, s, m, l, r, v);
	update(i*2+1, m+1, e, l, r, v);
}

vector<ll> ans;

void dnc(ll i, ll l, ll r) {
    ll cnt=0, m=l+r>>1;
    for(auto [u,v]:T[i]) cnt+=Union(u,v);
    if(l==r) {
        if(Q[l].first) ans.push_back(Find(Q[l].first) == Find(Q[l].second));
    } else dnc(i*2,l,m), dnc(i*2+1,m+1,r);
    while(cnt--) Undo();
}

vector<pair<ll,ll>> cp[SZ], edge;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    vector<array<ll,3>> op;
    for(ll i=0,u,v,k;i<M;i++) {
        cin >> u >> v >> k;
        if(u>v) swap(u,v);
        cp[k].push_back({u,v});
        op.push_back({1,u,v});
    }
    ll aa,bb; cin >> aa >> bb;
    for(ll i=1;i<=K;i++) {
        for(auto [u,v]:cp[i]) op.push_back({2,u,v});
        op.push_back({3,aa,bb});
        for(auto [u,v]:cp[i]) op.push_back({1,u,v});
    }
    M = op.size();

    for(ll i=1;i<=max(N,M);i++) P[i]=i, R[i]=1;
    for(ll i=1;i<=M;i++) {
        auto [a,b,c] = op[i-1];
        if(b>c) swap(b,c);
        if(a==1) E[{b,c}]=i;
        else if(a==2) update(1,1,M,E[{b,c}], i, {b,c}), E.erase({b,c});
        else Q[i]={b,c};
    }
    for(auto [i,j]:E) update(1,1,M,j,M,i);
    dnc(1,1,M);

    vector<ll> dap;
    for(ll i=0;i<K;i++) if(ans[i]) dap.push_back(i+1);
    cout << dap.size() << "\n";
    for(ll i:dap) cout << i << ' ';
    return 0;
}