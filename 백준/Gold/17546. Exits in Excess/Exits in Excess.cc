#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, IN[202020], U[202020], A[202020];
set<pair<int,int>> G[202020], R[202020];

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=M;i++) {
        int u,v; cin >> u >> v;
        G[u].insert({v,i});
        R[v].insert({u,i});
        IN[v]++;
    }
    set<int> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    for(int i=1;i<=N;i++) {
        pq.push({IN[i],i});
    }
    while(pq.size()) {
        auto [indeg, v] = pq.top(); pq.pop();
        if(A[v]) continue;
        A[v]=1;
        for(auto [i,idx]:R[v]) {
            ans.insert(idx);
            G[i].erase({v,idx});
        }
        IN[v]=0;
        for(auto [i,idx]:G[v]) {
            pq.push({--IN[i],i});
            R[i].erase({v,idx});
        }
    }
    cout << ans.size() << '\n';
    for(int i:ans) cout << i << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}