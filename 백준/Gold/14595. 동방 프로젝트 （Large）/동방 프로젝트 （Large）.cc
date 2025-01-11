#include <bits/stdc++.h>
using namespace std;

int N, M, P[1<<20];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[u]=v, true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    init(N);
    for(int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        if(u>v) swap(u,v);
        u=Find(u), v=Find(v);
        while(u!=v) Union(u,u+1), u=Find(u);
    }
    int cnt=0;
    for(int i=1;i<=N;i++) cnt+=P[i]==i;
    cout << cnt;
    return 0;
}