#include <bits/stdc++.h>
using namespace std;

int N, M, P[303030], S[303030], A[55][55];
void init(int n) { for(int i=0;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }
int idx(int x, int y) {return x*M+y;}
pair<int,int> dir[]= {{0,-1},{-1,0},{0,1},{1,0}};

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    init(N*M);
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        cin >> A[i][j];
    }
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        for(int t=0;t<4;t++) if(~A[i][j] & (1<<t)) {
            auto [dx,dy]=dir[t];
            Union(idx(i+dx,j+dy), idx(i,j));
        }
    }
    int mx=0, cnt=0, s=0;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        if(idx(i,j) == Find(idx(i,j))) cnt++, s=max(s, S[idx(i,j)]);
        if(i+1<N) {
            int u=Find(idx(i,j)), v=Find(idx(i+1,j));
            if(u!=v) mx=max(mx, S[u]+S[v]);
        }
        if(j+1<M) {
            int u=Find(idx(i,j)), v=Find(idx(i,j+1));
            if(u!=v) mx=max(mx, S[u]+S[v]);
        }
    }
    cout << cnt << '\n' << s << '\n' << mx;
    return 0;
}