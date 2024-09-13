#include <bits/stdc++.h>
using namespace std;

int N, M, U[2020];
vector<int> G[2020];

int bt(int v, int d=1) {
    if(d>=5) return 1;
    int res=0;
    for(int i:G[v]) if(!U[i]) U[i]=1, res|=bt(i,d+1), U[i]=0;
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1,u,v;i<=M;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    for(int i=0;i<N;i++) {
        U[i]=1;
        if(bt(i)) return cout << 1, 0;
        U[i]=0;
    }
    cout << 0;
    return 0;
}