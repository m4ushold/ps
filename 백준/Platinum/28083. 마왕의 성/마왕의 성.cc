#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, A[1010][1010], P[1010101], S[1010101], R[1010][1010];
vector<pll> dir({
    {1,0},{0,1},{-1,0},{0,-1}
});
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[u]=v, S[v]+=S[u], true); }

int idx(int x, int y) {
    return (x-1)*M+y;
}
bool chk(int x, int y) {
    return 1<=min(x,y) && x<=N && y<=M;
}

void sol(int tc) {
    cin >> N >> M;
    init(N*M);
    map<int,vector<pll>> m;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        m[A[i][j]].push_back({i,j});
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> S[idx(i,j)];
    for(auto [i,v]:m) {
        for(auto [x,y]:v) {
            for(auto [dx,dy]:dir) if(chk(x+dx,y+dy) && A[x+dx][y+dy] <= A[x][y]) Union(idx(x,y),idx(x+dx,y+dy));
        }
        for(auto [x,y]:v) {
            R[x][y] = S[Find(idx(x,y))];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) cout << R[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}