#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ=1<<18;
int N, Q, TOP[SZ], P[SZ], D[SZ], S[SZ], IN[SZ];
vector<int> T[SZ];

struct SegTree {
    ll T[SZ<<1];
    void build() { for(int i=SZ-1;i>=1;i--) T[i]=max(T[i*2],T[i*2+1]); }
    void update(int v, int x) {
        v|=SZ, T[v]=x;
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=SZ,r|=SZ ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
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
        res = max(res,seg.query(IN[TOP[u]], IN[u]));
    }
    if(IN[u] > IN[v]) swap(u, v);
    res = max(res,seg.query(IN[u]+1, IN[v])); // 정점 쿼리는 IN[u], 간선 쿼리는 IN[u]+1
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=2,a;i<=N;i++) cin >> a, T[a].push_back(i);
    DFS0(1); DFS1(1); DFS2(TOP[1]=1);

    for(int i=0,b,c,d;i<Q;i++) {
        cin >> b >> c >> d;
        if(d==0) cout << (qry(b,c) ? "NO\n" : "YES\n");
        else if(qry(b,c)) cout << "NO\n", upd(c,1);
        else cout << "YES\n", upd(b,1);
    }
    return 0;
}