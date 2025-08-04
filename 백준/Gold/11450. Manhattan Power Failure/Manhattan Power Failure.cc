#include <bits/stdc++.h>
using namespace std;

int N, M, P, C, A[1010101];
void init(int n) { for(int i=0;i<=n;i++) A[i]=i; }
int Find(int v) { return A[v]==v?v:A[v]=Find(A[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (A[u]=v, true); }
int idx(int i, int j) {return i*M+j;}

void sol() {
    cin >> N >> M >> P >> C;
    init(N*M);
    for(int i=0,x,y;i<P;i++) {
        cin >> x >> y;
        Union(N*M, idx(x,y));
    }
    for(int i=1,x,y;i<=C;i++) {
        char c; cin >> x >> y >> c;
        if(c=='U') Union(idx(x,y),idx(x,y+1));
        else Union(idx(x,y),idx(x+1,y));
    }

    int cnt=0;
    for(int i=0;i<N*M;i++) if(Find(i)==i && Find(i) != Find(N*M)) {
        cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}