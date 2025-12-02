#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, P[303030], S[303030], A[505][505];

int idx(int i, int j) { return (i-1)*M+j; }
pair<int,int> idx(int n) { return {n/M+!!(n%M), n%M?n%M:M}; }

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
void Union(int u, int v) {
    u=Find(u),v=Find(v);
    if(u==v) return;
    // cout << u << ": " << idx(u).first << ", " << idx(u).second << endl;
    if(A[idx(u).first][idx(u).second]<A[idx(v).first][idx(v).second]) swap(u,v);
    P[u]=v; S[v]+=S[u];
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    Init(N*M);
    for(int i=0;i<505;i++) for(int j=0;j<505;j++) A[i][j]=1e9;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        vector<pair<int,int>> v({{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}});
        int mn=A[i][j], u=idx(i,j);
        for(auto [dx,dy]:v) if(A[i+dx][j+dy]<mn) u=idx(i+dx,j+dy), mn=A[i+dx][j+dy];
        Union(idx(i,j), u);
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) cout << (P[idx(i,j)]==idx(i,j)?S[idx(i,j)]:0) << ' ';
        cout << '\n';
    }


    return 0;
}