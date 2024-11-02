#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll INF=INT_MAX;
ll N, M, D[50505], P[18][50505], MX[18][50505], MX2[18][50505];
vector<pair<ll,ll>> G[50505];
void dfs(ll v=1, ll b=-1) { for(auto [i,w]:G[v]) if(i!=b) MX[0][i]=w, MX2[0][i]=-1, D[i]=D[v]+1, P[0][i]=v, dfs(i,v); }

ll lca(ll u, ll v) {
    if(D[u]<D[v]) swap(u,v);
    ll diff=D[u]-D[v];
    for(ll i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(ll i=17;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

pair<ll,ll> calc(ll a, ll b, ll c, ll d) {
    ll mx=max({a,b,c,d}), mx2=-1;
    for(ll i:{a,b,c,d}) if(i<mx) mx2=max(mx2, i);
    return {mx, mx2};
}

pair<ll,ll> f(ll u, ll v) {
    pair<ll,ll> res={-1,-1};
    for(ll i=17;i>=0;i--) {
        if(D[P[i][v]] >= D[u]) {
            res = calc(res.first, res.second, MX[i][v], MX2[i][v]);
            v=P[i][v];
        }
    }
    return res;
}

pair<ll,ll> sub(ll u, ll v, ll w) {
    ll l = lca(u,v);
    auto a = f(l,u), b=f(l,v);
    return calc(a.first, a.second, b.first, b.second);
}

ll PP[50505], S[50505];
void init(ll n) { for(ll i=1;i<=n;i++) PP[i]=i,S[i]=1; }
ll Find(ll v) { return PP[v]==v?v:PP[v]=Find(PP[v]); }
bool Union(ll u, ll v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), PP[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(MX, -1, sizeof(MX));
    memset(MX2, -1, sizeof(MX2));

    cin >> N >> M;
    init(N);
    vector<tuple<ll,ll,ll>> edge, ex;
    for(ll i=0,a,b,c;i<M;i++) {
        cin >> a >> b >> c;
        edge.push_back({c,a,b});
    }
    ll mst=0;
    sort(edge.begin(),edge.end());
    map<pair<int,int>,int> mp;
    for(auto [w,s,e]:edge) {
        if(Union(s,e)) mst+=w, G[s].push_back({e,w}), G[e].push_back({s,w});
        else ex.push_back({w,s,e});
    }
    if(S[Find(1)]!=N) return cout << -1, 0;

    dfs();
    for(ll i=1;i<18;i++) for(ll j=1;j<=N;j++) {
        P[i][j]=P[i-1][P[i-1][j]];
        auto [mx, mx2] = calc(MX[i-1][j], MX[i-1][P[i-1][j]], MX2[i-1][j], MX2[i-1][P[i-1][j]]);
        MX[i][j] = mx, MX2[i][j]=mx2;
    }

    ll mn=INF;
    for(auto [w,s,e]:ex) {
        auto [w1,w2] = sub(s,e,w);
        if(w1 == w) w1 = w2;
        if(w!=w1 && w1>=0) mn=min(mn, mst+w-w1);
    }
    cout << (mn==INF || mn==mst ? -1 : mn);
    return 0;
}