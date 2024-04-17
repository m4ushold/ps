#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<16;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], SP[SZ], A[SZ], V[SZ];
vector<int> G[SZ], T[SZ];
ll m(ll a, ll b) { return a+b; }

struct SegTree {
    ll T[SZ<<1];    
    void build() { for(int i=SZ-1;i>=1;i--) T[i]=m(T[i*2],T[i*2+1]); }
    void update(int v, int x) {
        v|=SZ, T[v]=x;
        while(v>>=1) T[v]=m(T[v*2],T[v*2+1]);
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=SZ,r|=SZ ; l<=r ; l/=2,r/=2) {
            if(l&1) res=m(res,T[l++]);
            if(~r&1) res=m(res,T[r--]);
        }
        return res;
    }
} seg;

void DFS0(int v=1, int p=-1){
    V[v]=1;
    for(auto i:G[v]) if(p!=i) T[v].push_back(i), D[i]=D[v]+1, P[i]=v, DFS0(i,v);
}

void DFS1(int v=1){
    S[v] = 1;
    for(auto &i : T[v]){
        DFS1(i); S[v] += S[i];
        if(S[i] > S[T[v][0]]) swap(i, T[v][0]);
    }
}

void DFS2(int v=1){
    static int pv = 0; IN[v] = ++pv;
    for(auto i : T[v]) TOP[i] = i == T[v][0] ? TOP[v] : i, DFS2(i);
}

void upd(int x, int v) { seg.update(IN[x], v); }

ll qry(int u, int v){
    ll res = 0;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res = m(res,seg.query(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = m(res,seg.query(IN[u], IN[v])); // 정점 쿼리는 IN[u], 간선 쿼리는 IN[u]+1
    return res;
}

void build() {
    for(int i=1;i<=N;i++) seg.T[SZ|IN[i]]=A[i];
    seg.build();
}

int Find(int v) { return SP[v]==v?v:SP[v]=Find(SP[v]); }
void Init(int n) { for(int i=1;i<=n;i++) SP[i]=i;}
bool Union(int u, int v) { return Find(u)!=Find(v) && (SP[SP[u]]=SP[v], true); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    cin >> Q;
    vector<tuple<string,int,int>> q(Q);
    Init(N);
    for(auto &[c,i,j]:q) {
        cin >> c >> i >> j;
        if(c=="bridge" && Union(i,j)) G[i].push_back(j), G[j].push_back(i);
    }
    
    for(int i=1;i<=N;i++) if(!V[i]) DFS0(i), DFS1(i), DFS2(TOP[i]=i);
    build();

    Init(N);
    for(auto [s,i,j]:q) {
        if(s=="bridge") cout << (Union(i,j) ? "yes\n" : "no\n");
        else if(s=="penguins") upd(i,j);
        else if(s=="excursion") cout << (Find(i)==Find(j) ? to_string(qry(i,j))+"\n" : "impossible\n");
    }

    return 0;
}