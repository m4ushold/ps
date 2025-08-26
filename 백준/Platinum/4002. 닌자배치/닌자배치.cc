#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, C[101010], L[101010], S[101010], R;
vector<int> G[101010];
priority_queue<int> PQ[101010];

void dfs(int v, int p=-1) {
    PQ[v].push(C[v]);
    S[v]+=C[v];
    for(int i:G[v]) {
        dfs(i,v);
        if(PQ[v].size() < PQ[i].size()) swap(PQ[v], PQ[i]);
        S[v]+=S[i];
    }
    for(int i:G[v]) {
        while(PQ[i].size()) PQ[v].push(PQ[i].top()), PQ[i].pop();
    }

    while(S[v]>M && PQ[v].size()) S[v]-=PQ[v].top(), PQ[v].pop();
    R=max<ll>(R, PQ[v].size() * L[v]);
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        int b; cin >> b >> C[i] >> L[i];
        G[b].push_back(i);
    }
    dfs(G[0][0]);
    cout << R;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}