#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<18;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ];
vector<int> T[SZ], G[SZ];

ll m(ll a, ll b) {return a+b;}

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

void DFS0(int v){
    for(auto i : T[v]) D[i]=D[v]+1, P[i]=v, DFS0(i);
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
}

void upd(int x, int v) { seg.update(IN[x], v); }

ll qry(int u, int v){
    ll res = 0;
    for(; TOP[u] != TOP[v]; u=P[TOP[u]]){
        if(D[TOP[u]] < D[TOP[v]]) swap(u, v);
        res = m(res,seg.query(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = m(res,seg.query(IN[u], IN[v]));
    if(seg.query(IN[u],IN[u])) return res-1;
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=2,a;i<=N;i++) cin >> a, T[a].push_back(i);
    DFS0(1); DFS1(1); DFS2(TOP[1]=1);
    for(int i=1;i<=N;i++) seg.T[SZ|IN[i]]=1;
    seg.build();

    cin >> Q;
    for(int i=0,a,b,c;i<Q;i++) {
        cin >> a >> b;
        if(a&1) cin >> c, cout << qry(b,c) << '\n';
        else upd(b,0);
    }
    return 0;
}