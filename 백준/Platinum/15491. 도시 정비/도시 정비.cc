#include <bits/stdc++.h>
using namespace std;

struct Seg {
    static const int sz=1<<20;
    int T[sz<<1];
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=max(T[i*2],T[i*2+1]); }
    int qry(int l, int r) {
        int ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=max(ret,T[l++]);
            if(~r&1) ret=max(ret,T[r--]);
        }
        return ret;
    }
} seg;

int N, A[1010101], IN[1010101], OUT[1010101], D[1010101];
vector<int> G[1010101];

int dfs(int v=1, int p=-1) {
    static int pv=0;
    IN[v]=++pv;
    int mx=0;
    for(int i:G[v]) if(i!=p) {
        int t=dfs(i,v);
        mx=max(mx,t);
        D[v]+=t;
    }
    OUT[v]=pv;
    return max(mx,A[v]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs();
    for(int i=1;i<=N;i++) seg.T[seg.sz|IN[i]] = A[i];
    seg.bld();

    int mx=0;
    for(int i=1;i<=N;i++) {
        mx=max(mx,D[i]+max(seg.qry(1, IN[i]-1), seg.qry(OUT[i]+1, N)));
    }
    cout << mx;
    return 0;
}