#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, vi[202020], D[202020], A[202020], B[202020];
vector<pair<ll,ll>> G[202020];

void dijkstra(ll s) {
    for(ll i=1;i<=N+1;i++) D[i]=LONG_LONG_MAX/2, vi[i]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<>> pq;
    D[s]=0; pq.emplace(0,s);
    while(!pq.empty()) {
        auto [c,v] = pq.top(); pq.pop();
        if(vi[v]) continue; vi[v]=1;
        for(auto [i,w]:G[v]) {
            if(D[i]>D[v]+w){
                D[i]=D[v]+w;
                pq.emplace(D[i], i);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(ll i=1;i<=N;i++) cin >> A[i];
    for(ll i=1;i<=N;i++) cin >> B[i];
    for(ll i=1;i<=N;i++) {
        if(i-A[i]<1 || i+A[i]>N) {
            G[N+1].push_back({i,B[i]});
        }
        // i-A[i]
        if(1<=i-A[i]) {
            G[i-A[i]].push_back({i,B[i]});
        }
        // i+A[i]
        if(i+A[i]<=N) {
            G[i+A[i]].push_back({i,B[i]});
        }
    }

    dijkstra(N+1);
    for(ll i=1;i<=N;i++) cout << D[i] << ' ';
    return 0;
}