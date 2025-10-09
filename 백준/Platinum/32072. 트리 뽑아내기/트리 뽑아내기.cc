#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, A[303030];
vector<int> G[303030];

void sol(int tc) {
    cin >> N;
    for(int i=2;i<=N;i++) {
        int p; cin >> p;
        G[p].push_back(i);
    }
    for(int i=1;i<=N;i++) cin >> A[i];
    priority_queue<pll,vector<pll>,greater<>> pq;
    pq.push({A[1],1});
    while(pq.size()) {
        auto [c,v] = pq.top(); pq.pop();
        cout << c << '\n';
        for(int i:G[v]) pq.push({A[i],i});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}