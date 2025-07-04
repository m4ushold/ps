#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<17, inf = 1e14;
ll N, M, S, P[sz], TOT, D[11][sz];
pair<ll,ll> A[11];
vector<pair<ll,ll>> G[sz];

struct Dinic {
    struct edge_t {int v,r; ll c,f;};
    int n;
    vector<vector<edge_t>> g;
    vector<int> lv, idx;
    Dinic(int n) : n(n) { 
        g=vector<vector<edge_t>>(n);
        lv=vector<int>(n);
        idx=vector<int>(n);
    }
    void addEdge(int s, int e, ll c1, ll c2=0) {
        g[s].push_back(edge_t{e,(int)g[e].size(),c1,0});
        g[e].push_back(edge_t{s,(int)g[s].size()-1,c2,0});
    }
    bool bfs(int s, int t, ll limit=1) {
        fill(lv.begin(),lv.end(),0);
        queue<int> q;
        q.push(s), lv[s]=1;
        while(!q.empty()) {
            int v=q.front(); q.pop();
            for(auto e:g[v]) if(!lv[e.v] && e.c-e.f>=limit) q.push(e.v), lv[e.v]=lv[v]+1;
        }
        return lv[t]!=0;
    }
    ll dfs(int v, int t, ll f1=inf) {
        if(v==t || f1==0) return f1;
        for(auto &e:g[v]) {
            if(lv[e.v] != lv[v]+1 || e.c-e.f==0) continue;
            ll now=dfs(e.v,t,min(f1,e.c-e.f));
            if(now==0) continue;
            e.f+=now, g[e.v][e.r].f-=now;
            return now;
        }
        return 0;
    }
    ll mf(int s, int t) {
        ll mf=0, f=0;
        while(bfs(s,t)) {
            fill(idx.begin(),idx.end(),0);
            while((f=dfs(s,t)) != 0) mf+=f;
        }
        return mf;
    }
};


bool chk(ll t) {
    Dinic g(3030);
    vector<ll> w(3030);
    for(int i=1;i<=N;i++) {
        int f = 0;
        for(int s=0;s<S;s++) if(D[s][i] <= t) f|=1<<s;
        w[f]+=P[i];
    }
    for(int i=0;i<2048;i++) g.addEdge(i, 3001, w[i]);
    for(int i=0;i<S;i++) g.addEdge(3000, 2048+i, A[i].second);
    for(int i=0;i<2048;i++) for(int j=0;j<S;j++) {
        if(i&(1<<j)) g.addEdge(2048+j, i, inf);
    }
    return g.mf(3000, 3001) == TOT;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> S;
    for(ll i=1;i<=N;i++) cin >> P[i], TOT += P[i];
    for(ll i=0,s,e,w;i<M;i++) cin >> s >> e >> w, G[s].push_back({e,w}), G[e].push_back({s,w});
    for(ll i=0;i<S;i++) cin >> A[i].first >> A[i].second;

    for(int i=0;i<S;i++) {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
        for(int j=1;j<=N;j++) D[i][j] = inf;
        pq.push({D[i][A[i].first]=0, A[i].first});
        while(pq.size()) {
            auto [c,v] = pq.top(); pq.pop();
            for(auto [u,w]:G[v]) {
                if(D[i][u] > D[i][v] + w) {
                    D[i][u] = D[i][v] + w;
                    pq.push({D[i][u], u});
                }
            }
        }
    }
    vector<ll> v;
    for(int i=0;i<S;i++) for(int j=1;j<=N;j++) {
        v.push_back(D[i][j]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());

    ll l=0, r=v.size()-1;
    while(l<r) {
        ll m = (l+r)>>1;
        if(chk(v[m])) r=m;
        else l=m+1;
    }
    cout << v[r];
    return 0;
}