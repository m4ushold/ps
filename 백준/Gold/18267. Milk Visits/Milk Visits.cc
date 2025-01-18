#include <bits/stdc++.h>
using namespace std;

int N, M, P[1<<17], S[1<<17];
char A[1<<17];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    init(N);
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        if(A[u]==A[v]) Union(u,v);
    }

    for(int i=0,u,v;i<M;i++) {
        char c; cin >> u >> v >> c;
        int f=1;
        if(c!=A[v] && c!=A[u] && Find(u) == Find(v)) f=0;
        cout << f;
    }
    return 0;
}