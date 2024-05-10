#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<17;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ];
vector<int> G[SZ];

inline ll merge(ll a, ll b) { return max(a,b); }

struct SegTree {
    ll T[SZ<<1];
    void build() { for(int i=SZ-1;i>=1;i--) T[i]=merge(T[i*2],T[i*2+1]); }
    void upd(int i, ll x) {
        i|=SZ, T[i]=x;
        while(i>>=1) T[i]=merge(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r) {
        ll res=0;
        for(l|=SZ,r|=SZ ; l<=r ; l/=2,r/=2) {
            if(l&1) res=merge(res,T[l++]);
            if(~r&1) res=merge(res,T[r--]);
        }
        return res;
    }
} seg;

struct HLD {
    void f(int v=1, int p=-1) { 
        S[v]=1;
        for(auto &i:G[v]) if(i!=p) {
            D[i]=D[v]+1, P[i]=v, f(i,v), S[v]+=S[i];
            if(S[G[v][0]] < S[i]) swap(G[v][0],i);
        } 
    }
    void g(int v=1, int p=-1) {
        static int pv = 0; IN[v] = ++pv;
        for(auto i : G[v]) if(i!=p) TOP[i] = i == G[v][0] ? TOP[v] : i, g(i,v);
    }
    void build() { f(), g(TOP[1]=1); }

    void upd(int u, int x) { seg.upd(IN[u], x); }
    ll qry(int u, int v){
        ll res = 0;
        for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
            if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
            res = merge(res,seg.qry(IN[TOP[u]], IN[u]));
        }
        if(IN[u] > IN[v]) swap(u, v);
        res = merge(res,seg.qry(IN[u]+1, IN[v]));
        return res;
    }
} tree;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<tuple<int,int,int>> E(N);
    for(int i=1;i<N;i++) {
        auto &[s,e,w]=E[i]; cin >> s >> e >> w;
        G[s].push_back(e), G[e].push_back(s);
    }
    tree.build();

    for(auto &[s,e,w]:E) {
        if(D[s]>D[e]) swap(s,e);
        seg.T[SZ|IN[e]]=w;
    }
    seg.build();

    cin >> Q;
    for(int i=0,a,b,c;i<Q;i++) {
        cin >> a >> b >> c;
        if(a&1) tree.upd(get<1>(E[b]),c);
        else cout << tree.qry(b,c) << '\n';
    }
    return 0;
}