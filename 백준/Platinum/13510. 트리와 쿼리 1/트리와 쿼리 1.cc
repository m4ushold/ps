#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int SZ=101010;
int N, Q, A[SZ], Top[SZ], Par[SZ], Dep[SZ], Sz[SZ], In[SZ];
vector<int> Inp[SZ], G[SZ];

struct SegTree {
    ll T[1<<18], sz=1<<17;
    void build() { for(int i=sz-1;i>=1;i--) T[i]=max(T[i*2],T[i*2+1]); }
    void update(int v, int x) {
        v|=sz, T[v]=x;
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

void Connect(int u, int v){ Inp[u].push_back(v); Inp[v].push_back(u); }

void DFS0(int v, int b=-1){
    for(auto i : Inp[v]) if(i != b)
        Dep[i] = Dep[v] + 1, Par[i] = v, G[v].push_back(i), DFS0(i, v);
}

void DFS1(int v){
    Sz[v] = 1;
    for(auto &i : G[v]){
        DFS1(i); Sz[v] += Sz[i];
        if(Sz[i] > Sz[G[v][0]]) swap(i, G[v][0]);
    }
}

void DFS2(int v){
    static int pv = 0; In[v] = ++pv;
    for(auto i : G[v]) Top[i] = i == G[v][0] ? Top[v] : i, DFS2(i);
}

void VertexUpdate(int x, int v) { seg.update(In[x], v); }

ll PathQuery(int u, int v){
    ll res = 0;
    for(; Top[u] != Top[v]; u=Par[Top[u]]){
        if(Dep[Top[u]] < Dep[Top[v]]) swap(u, v);
        res = max(res,seg.query(In[Top[u]], In[u]));
    }
    if(In[u] > In[v]) swap(u, v);
    res = max(res,seg.query(In[u]+1, In[v])); // 정점 쿼리는 In[u], 간선 쿼리는 In[u]+1
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<tuple<int,int,int>> E(N);
    for(int i=1;i<N;i++) {
        auto &[s,e,w]=E[i]; cin >> s >> e >> w;
        Inp[s].push_back(e), Inp[e].push_back(s);
    }
    DFS0(1); DFS1(1); DFS2(Top[1]=1);

    for(auto &[s,e,w]:E) {
        if(Dep[s]>Dep[e]) swap(s,e);
        seg.T[seg.sz|In[e]]=w;
    }
    seg.build();

    cin >> Q;
    for(int i=0,a,b,c;i<Q;i++) {
        cin >> a >> b >> c;
        if(a&1) VertexUpdate(get<1>(E[b]),c);
        else cout << PathQuery(b,c) << '\n';
    }
    return 0;
}