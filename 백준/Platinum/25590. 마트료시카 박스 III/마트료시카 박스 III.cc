#include <bits/stdc++.h>
using namespace std;

int N, M, K, S, IN[606060], OUT[606060], P[303030], F=1;
vector<int> G[606060];

void dfs(int v) {
    static int pv=0;
    IN[v]=++pv;
    if(G[v].size() > M) F=0;
    for(int i:G[v]) dfs(i);
    OUT[v]=pv;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K >> S;
    for(int i=1,n,a;i<=N;i++) {
        cin >> n;
        while(n--) cin >> a, P[a]=i;
    }

    for(int i=1,n,a;i<=N+S;i++) {
        cin >> n;
        while(n--) cin >> a, G[i].push_back(a);
    }
    int rt=1;
    while(P[rt]) rt = P[rt];
    dfs(rt);

    for(int i=1;i<=N;i++) if(P[i]) {
        int p=P[i];
        if(IN[p] >= IN[i] || IN[i] > OUT[p]) F=0;
    }
    if(K<S) F=0;
    cout << F;
    return 0;
}