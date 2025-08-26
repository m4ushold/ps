#include <bits/stdc++.h>
using namespace std;

int N, A[202020], R[202020];
vector<int> G[202020];
set<int> S[202020];

void dfs(int v) {
    S[v].insert(A[v]);
    for(int i:G[v]) {
        dfs(i);
        if(S[i].size() > S[v].size()) swap(S[v],S[i]);
        R[v]=max(R[v],R[i]);
    }
    for(int i:G[v]) for(int j:S[i]) S[v].insert(j);
    while(S[v].count(R[v])) R[v]++;
}

void sol(int tc) {
    cin >> N;
    for(int i=1,p;i<=N;i++) {
        cin >> p;
        if(p==-1) p=0;
        G[p].push_back(i);
    }
    for(int i=1;i<=N;i++) cin >> A[i];
    dfs(G[0][0]);
    for(int i=1;i<=N;i++) cout << R[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}