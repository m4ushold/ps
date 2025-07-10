#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr ll sz = 1<<17, inf = 1e9+7;
ll N, M, K, D1[sz], D2[sz], V[sz];
vector<pair<ll,ll>> G[sz];

void dijk(vector<int> &k) {
    for(int i=0;i<N;i++) D1[i]=D2[i]=inf;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    for(int i:k) pq.emplace(D1[i]=D2[i]=0, i);

    while(pq.size()) {
        auto [c,v] = pq.top(); pq.pop();
        if(V[v]) continue;
        V[v]=1;
        for(auto [i,w]:G[v]) {
            ll cost = D2[v] + w;
            if(D1[i] > cost) swap(D1[i], cost);
            if(D2[i] > cost) pq.emplace(D2[i] = cost, i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for(int i=0,s,e,w;i<M;i++) {
        cin >> s >> e >> w;
        G[s].emplace_back(e,w), G[e].emplace_back(s,w);
    }
    vector<int> v(K);
    for(int &i:v) cin >> i;
    dijk(v);
    cout << D2[0];
    return 0;
}