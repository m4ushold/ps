#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
int N, A[sz], C[sz], D[sz];
vector<int> G[sz], F[sz];

ll dfs(int v=1) {
    ll res = D[A[v]] - C[A[v]];
    for(int i:F[A[v]]) res += C[i];
    for(int i:F[A[v]]) D[i]++;
    C[A[v]]++;
    for(int i:G[v]) res += dfs(i);
    for(int i:F[A[v]]) D[i]--;
    C[A[v]]--;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=2,p;i<=N;i++) cin >> p, G[p].push_back(i);
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j+=i) F[j].push_back(i);
    cout << dfs();
    return 0;
}