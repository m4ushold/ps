#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<17;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ], A[SZ];
vector<int> G[SZ], T[SZ];

ll merge(ll a, ll b) { return a+b; }

struct SegTree {
    vector<ll> T[SZ<<1];
    void build(){
        for(int i=SZ-1; i; i--){
            T[i].resize(T[i*2].size() + T[i*2+1].size());
            merge(T[i*2].begin(),T[i*2].end(), T[i*2+1].begin(),T[i*2+1].end(), T[i].begin());
        }
    }
    ll qry(int l, int r, int s, int e) {
        ll res=0;
        for(l|=SZ,r|=SZ ; l<=r ; l/=2,r/=2) {
            if(l&1) res+=accumulate(lower_bound(T[l].begin(),T[l].end(),s), upper_bound(T[l].begin(),T[l].end(),e), 0LL), l++;
            if(~r&1) res+=accumulate(lower_bound(T[r].begin(),T[r].end(),s), upper_bound(T[r].begin(),T[r].end(),e), 0LL), r--;
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
    ll qry(int u, int v, int l, int r){
        ll res = 0;
        for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
            if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
            res+=seg.qry(IN[TOP[u]], IN[u], l, r);
        }
        if(IN[u] > IN[v]) swap(u, v);
        res+=seg.qry(IN[u], IN[v], l, r);
        return res;
    }
} tree;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    tree.build();
    for(int i=1;i<=N;i++) seg.T[SZ|IN[i]].push_back(A[i]);
    seg.build();

    for(int i=0,a,b,l,r;i<Q;i++) {
        cin >> a >> b >> l >> r;
        cout << tree.qry(a,b,l,r) << '\n';
    }
    return 0;
}