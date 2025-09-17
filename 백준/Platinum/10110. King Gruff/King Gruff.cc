#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1 << 17;
ll N, M, A, B, Q, D[2][sz], P[sz];
vector<pll> G[sz], R[sz];
vector<array<int,4>> E;

void dijk(int s, int idx) {
    for(int i=1;i<=N;i++) D[idx][i]=1e9;
    priority_queue<pll,vector<pll>,greater<>> pq;
    pq.push({D[idx][s]=0,s});

    while(pq.size()) {
        auto [c,v] = pq.top(); pq.pop();
        if(D[idx][v] < c) continue;
        auto &g = idx ? R[v] : G[v];
        for(auto [i,w]:g) {
            if(D[idx][i] > D[idx][v] + w) {
                D[idx][i] = D[idx][v] + w;
                pq.push({D[idx][i],i});
            }
        }
    }
}

void sol(int tc) {
    cin >> N >> M >> A >> B;
    for(int i=1;i<=M;i++) {
        int u,v,l,c; cin >> u >> v >> l >> c;
        E.push_back({u,v,l,c});
        G[u].push_back({v,l});
        R[v].push_back({u,l});
    }
    dijk(A, 0), dijk(B, 1);
    map<ll,ll> m;
    for(auto [u,v,l,c]:E) {
        ll dst = D[0][u]+D[1][v]+l;
        m[dst]+=c;
    }
    m[0]=0;
    vector<pll> v(m.begin(),m.end());
    for(int i=1;i<v.size();i++) v[i].second += v[i-1].second;

    cin >> Q;
    for(ll i=0,x;i<Q;i++) {
        cin >> x;
        int j = upper_bound(v.begin(),v.end(),make_pair(x,(ll)1e9))-v.begin()-1;
        cout << v[j].second << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}