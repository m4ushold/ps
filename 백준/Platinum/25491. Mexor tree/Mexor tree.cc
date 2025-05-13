#include <bits/stdc++.h>
using namespace std;

const int sz=1<<19;
int N, S, M, A[sz], B[sz], D[sz], P[22][sz], R[sz];
vector<int> G[sz];
void dfs(int v, int b=-1) { for(auto i:G[v]) if(i!=b) D[i]=D[v]+1, P[0][i]=v, dfs(i,v); }

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}
void build() {
    dfs(S);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
}
void d1(int v, int p=-1) {
    for(int i:G[v]) if(i!=p) d1(i,v), B[v]^=B[i];
}
struct {
    int T[sz<<1], C[sz];
    void upd(int i, int x) {
        C[i]+=x;
        T[i|=sz]=C[i]>0;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    int mex() {
        int i=1, s=sz;
        while(i<sz) {
            i = i*2 | (T[i*2]*2 == s);
            s/=2;
        }
        return i^sz;
    }
} num_set;

void d2(int v, int p=-1) {
    num_set.upd(A[v]^B[v],1);
    R[v] = num_set.mex();
    for(int i:G[v]) if(i!=p) d2(i,v);
    num_set.upd(A[v]^B[v],-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    build();
    cin >> M;
    for(int i=0,x,y,z;i<M;i++) {
        cin >> x >> y >> z;
        B[x]^=z, B[y]^=z;
        int l=lca(x,y);
        B[l]^=z, B[P[0][l]]^=z;
    }
    d1(S);
    d2(S);
    for(int i=1;i<=N;i++) cout << R[i] << ' ';
    return 0;
}