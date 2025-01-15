#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> G[1<<18];
ll N, D[1<<18][2], A[1<<18];

void dfs(int v=1) {
    for(int i:G[v]) dfs(i), D[v][0]+=max(D[i][1], D[i][0]);
    for(int i:G[v]) D[v][1]=max(D[v][1], A[v]*A[i]+D[v][0]-max(D[i][1], D[i][0]) + D[i][0]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=2,p;i<=N;i++) cin >> p, G[p].push_back(i);
    for(int i=1;i<=N;i++) cin >> A[i];

    dfs();
    cout << max(D[1][0], D[1][1]);
    return 0;
}