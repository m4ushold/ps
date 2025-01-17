#include <bits/stdc++.h>
using namespace std;

int N, M, P[1<<20], S[1<<20];
char C[1010][1010];
void init(int n) { for(int i=0;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
int idx(int x, int y) {return x*M+y;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    init(N*M);
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        cin >> C[i][j];
        if(C[i][j]=='S') Union(idx(i,j),idx(i+1,j));
        else if(C[i][j]=='E') Union(idx(i,j),idx(i,j+1));
        else if(C[i][j]=='W') Union(idx(i,j),idx(i,j-1));
        else Union(idx(i,j),idx(i-1,j));
    }
    int cnt=0;
    for(int i=0;i<N*M;i++) if(i==P[i]) cnt++;
    cout << cnt;
    return 0;
}