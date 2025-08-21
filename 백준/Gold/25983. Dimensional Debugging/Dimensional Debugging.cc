#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, K, A[1010];
vector<int> G[1010], L[1010], H[1010];

void dfs(int v) {
    if(A[v]) return;
    A[v]=1;
    for(int i:G[v]) dfs(i);
}

void sol(int tc) {
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        int f=1;
        for(int j=0,x;j<K;j++) cin >> x, L[i].push_back(x), f&=(x?0:1);
        for(int j=0,x;j<K;j++) cin >> x, H[i].push_back(x);
        if(f) G[0].push_back(i);
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(i^j) {
        int f=1;
        for(int k=0;k<K;k++) if(L[j][k] > H[i][k]) f=0;
        if(f) G[i].push_back(j);
    }
    dfs(0);
    cout << accumulate(A, A+1010, 0)-1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}