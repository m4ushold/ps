#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<18;
ll N, L[sz], R[sz], I[sz];

int dfs(int v, ll k) {
    if(L[v] == R[v] && L[v]==-1) return v;
    if(L[v] == -1) return dfs(R[v], k);
    if(R[v] == -1) return dfs(L[v], k);
    if(k&1) return dfs(L[v], (k+1)/2);
    return dfs(R[v], k/2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> L[i] >> R[i], I[L[i]]++, I[R[i]]++;
    int rt=1;
    for(int i=1;i<=N;i++) if(I[i]==0) rt=i;
    ll k; cin >> k;
    cout << dfs(rt, k);
    return 0;
}