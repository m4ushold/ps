#include <bits/stdc++.h>
using namespace std;
using ll=unsigned;

constexpr int SZ=1<<19;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], OUT[SZ];
vector<int> G[SZ], T[SZ];

ll m(ll a, ll b) { return a+b; }

struct SegTree {
    ll T[SZ<<1], A[SZ<<1], B[SZ<<1];
    void init() { for(int i=0;i<SZ*2;i++) A[i]=1, B[i]=0; }
    void push(int node, int s, int e) {
        if(A[node]==1 && !B[node]) return;
        T[node]=T[node]*A[node]+ (e-s+1)*B[node];
        if(s!=e) for(int i:{node*2,node*2+1}) {
            A[i]*=A[node], B[i]=B[i]*A[node]+B[node];
        }
        A[node]=1, B[node]=0;
    }
    void upd(int l, int r, int a, int b, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {
            A[node]=a, B[node]=b, push(node,s,e); 
            return;
        }
        int m=s+e>>1;
        upd(l,r,a,b,node*2,s,m), upd(l,r,a,b,node*2+1,m+1,e);
        T[node]=T[node*2]+T[node*2+1];
    }
    ll qry(int l, int r, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return qry(l,r,2*node,s,m)+qry(l,r,2*node+1,m+1,e);
    }
} seg;

void DFS0(int v=1, int p=-1){
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
    OUT[v]=pv;
}

void updSubtree(int x, int a, int b) { seg.upd(IN[x], OUT[x], a, b); }
ll qrySubtree(int x) { return seg.qry(IN[x],OUT[x]); }

void updPath(int u, int v, int a, int b) {
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        seg.upd(IN[TOP[u]], IN[u], a, b);
    }
    if(IN[u] > IN[v]) swap(u, v);
    seg.upd(IN[u], IN[v],a, b);
}

ll qryPath(int u, int v){
    ll res = 0;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res = m(res,seg.qry(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = m(res,seg.qry(IN[u], IN[v]));
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    DFS0(), DFS1(), DFS2(TOP[1]=1);

    for(int i=0,q,x,y,v;i<Q;i++) {
        cin >> q >> x;
        if(q==1) cin >> v, updSubtree(x,1,v);
        else if(q==2) cin >> y >> v, updPath(x,y,1,v);
        else if(q==3) cin >> v, updSubtree(x,v,0);
        else if(q==4) cin >> y >> v, updPath(x,y,v,0);
        else if(q==5) cout << qrySubtree(x) << '\n';
        else cin >> y, cout << qryPath(x,y) << '\n';
    }
    return 0;
}