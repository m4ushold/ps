#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<18;
struct {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=T[i<<1]+T[i<<1|1];
    }
    int qry(int l, int r) {
        int res=0;
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

int N, M, IN[202020], OUT[202020], P[202020];
vector<int> G[202020];

void dfs(int v=1, int p=-1) {
    static int pv=0;
    IN[v] = ++pv;
    for(int i:G[v]) if(i!=p) dfs(i,v), P[i]=v;
    OUT[v] = pv;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for(int i=1;i<=N;i++) sort(G[i].begin(),G[i].end());
    dfs();
    for(int i=0,a;i<M;i++) {
        cin >> a;
        if(seg.qry(IN[a], N) - seg.qry(IN[a], OUT[a])) return cout << i, 0;
        seg.upd(IN[a], 1);
    }
    cout << M;
    return 0;
}