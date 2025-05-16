#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<19;
ll N, S[sz], D[sz], R;
vector<pair<int,int>> G[sz];

void d1(int v=1, int p=-1) {
    S[v]=1;
    for(auto [i,w]:G[v]) if(i!=p) d1(i,v), S[v]+=S[i], D[v]+=D[i] + w*S[i];
}

void d2(int v=1, int p=-1) {
    R=min(R,D[v]);
    for(auto [i,w]:G[v]) if(i!=p) D[i] = D[v]+(N - 2 * S[i]) * w, d2(i,v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1,u,v,w;i<N;i++) {
        cin >> u >> v >> w;
        G[u].push_back({v,w}), G[v].push_back({u,w});
    }
    d1(), d2();
    for(int i=1;i<=N;i++) cout << D[i] << '\n';
    return 0;
}