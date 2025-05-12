#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<17;
int N, A[sz], B[sz];
vector<int> G[sz];

ll dfs(int v=1, int p=-1) {
    ll ret=0;
    for(int i:G[v]) if(i!=p) {
        ret += dfs(i,v);
    }
    return max(A[v]*B[v]+ret,0LL);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=2,p;i<=N;i++) {
        char c; cin >> c >> A[i] >> p;
        G[i].push_back(p), G[p].push_back(i);
        B[i] = c=='S'?1:-1;
    }
    cout << dfs();
    return 0;
}