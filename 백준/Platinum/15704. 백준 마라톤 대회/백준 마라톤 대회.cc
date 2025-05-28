#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<17, inf = LLONG_MAX/8;
ll N, M, K, D[sz];
vector<array<ll,3>> G[sz];

ll weight(ll c, ll p, ll t) {
    return c * max(p-t, 0LL) * max(p-t, 0LL);
}

bool chk(ll p) {
    for(ll i=1;i<=N;i++) D[i] = inf;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<>> pq;
    D[1]=0; pq.emplace(0,1);
    while(!pq.empty()) {
        auto [c,v] = pq.top(); pq.pop();
        for(auto [i,c,t]:G[v]) {
            ll w = weight(c,p,t);
            if(D[i]>D[v]+w){
                D[i]=D[v]+w;
                pq.emplace(D[i], i);
            }
        }
    }
    return D[N] <= K;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for(ll i=1,a,b,c,t;i<=M;i++) {
        cin >> a >> b >> c >> t;
        G[a].push_back({b,c,t});
        G[b].push_back({a,c,t});
    }
    ll l=0, r=1e5;
    while(l<r) {
        ll m = l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    cout << l;
    return 0;
}