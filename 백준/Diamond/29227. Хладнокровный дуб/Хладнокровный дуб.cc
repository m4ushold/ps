#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr ll SZ=1<<18;
ll N, M, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], OUT[SZ];
vector<int> T[SZ], G[SZ];

struct SegTree {
    ll T[SZ<<1], L[SZ<<1];
    void push(int node, int s, int e) {
        if(L[node]==0) return;
        T[node]+=L[node]*(e-s+1);
        if(s!=e) for(int i:{node*2,node*2+1}) L[i]+=L[node];
        L[node]=0;
    }
    void upd(int l, int r, ll v, int node=1, int s=0, int e=SZ-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
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
    for(auto i:G[v]) if(p!=i) D[i]=D[v]+1, P[i]=v, DFS0(i,v), T[v].push_back(i);
}

void DFS1(int v){
    S[v] = 1;
    for(auto &i : T[v]){
        DFS1(i); S[v] += S[i];
        if(S[i] > S[T[v][0]]) swap(i, T[v][0]);
    }
}   

void DFS2(int v){
    static int pv = 0; IN[v] = ++pv;
    for(auto i : T[v]) TOP[i] = i == T[v][0] ? TOP[v] : i, DFS2(i);
    OUT[v] = pv;
}

void upd(int u, int v, ll w) { 
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        seg.upd(IN[TOP[u]], IN[u], w);
    }
    if(IN[u] > IN[v]) swap(u, v);
    seg.upd(IN[u]+1, IN[v], w);
}

ll qry(int u, int v){
    ll res = 0;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res += seg.qry(IN[TOP[u]], IN[u]);
    }
    if(IN[u] > IN[v]) swap(u, v);
    res += seg.qry(IN[u]+1, IN[v]);
    return res;
}

void sol(int tc) {
    cin >> N;
    for(int i=2,p;i<=N;i++) cin >> p, G[p].push_back(i);
    DFS0(1), DFS1(1), DFS2(TOP[1]=1);
    cin >> Q;
    for(int i=1,x,y;i<=Q;i++) {
        string op; cin >> op;
        if(op == "add") {
            cin >> x >> y;
            upd(1, x, y);
        } else if(op == "del") {
            cin >> x >> y;
            upd(1, x, -y);
        } else {
            cin >> x;
            cout << seg.qry(IN[x], OUT[x]) << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}