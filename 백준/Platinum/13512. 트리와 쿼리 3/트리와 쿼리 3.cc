#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<17;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], SP[SZ], A[SZ], V[SZ];
vector<int> G[SZ], T[SZ];

ll m(ll a, ll b) { 
    if(a && b) return IN[a] < IN[b] ? a : b;
    return a ? a : b;
}
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

void upd(int x, int v) { 
    if(seg.T[SZ|IN[x]]) v=0;
    seg.update(IN[x], v); 
}

ll qry(int u, int v){
    ll res = 0;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res = m(res,seg.query(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = m(res,seg.query(IN[u], IN[v]));
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    DFS0(), DFS1(), DFS2(TOP[1]=1);

    cin >> Q;
    for(int i=0,q,a;i<Q;i++) {
        cin >> q >> a;
        if(q&1) upd(a,a);
        else a=qry(1,a), cout << (a?a:-1) << '\n';
    }
    return 0;
}