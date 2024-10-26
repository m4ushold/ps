#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<18;
int N, Q, TOP[sz], S[sz], D[sz], P[sz], IN[sz];
vector<int> G[sz];

struct LzSeg {
    ll T[sz<<1], L[sz<<1];
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i] += L[i]*(e-s+1);
        if(s!=e) L[i*2]+=L[i], L[i*2+1]+=L[i];
        L[i]=0;
    }
    void update(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        if(l>r) return;
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        update(l,r,v,i*2,s,m), update(l,r,v,i*2+1,m+1,e);
        T[i]=(T[i*2]+T[i*2+1]);
    }
    ll query(int l, int r, int i=1, int s=0, int e=sz-1) {
        if(l>r) return 0;
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return query(l,r,i*2,s,m)+query(l,r,i*2+1,m+1,e);
    }
} seg;

void dfs1(int v=1, int p=-1) { // depth, parent
    for(int i:G[v]) if(i!=p) D[i]=D[v]+1, P[i]=v, dfs1(i,v);
}

int dfs2(int v=1, int p=-1) { // size
    S[v]=1;
    for(int &i:G[v]) if(i!=p) {
        S[v]+=dfs2(i,v);
        if(S[G[v][0]] < S[i]) swap(G[v][0], i);
    }
    return S[v];
}

void dfs3(int v=1, int p=-1) { // inorder, top
    static int pv=0;
    IN[v]=++pv;
    for(int i:G[v]) if(i!=p) {
        TOP[i]= (i==G[v][0] ? TOP[v] : i);
        dfs3(i,v);
    }
}

int lca(int u, int v) {
    for(;TOP[u]!=TOP[v];v=P[TOP[v]]) {
        if(D[TOP[u]] > D[TOP[v]]) swap(u,v);
    }
    return D[u] > D[v] ? v : u;
}

void update(int u, int v) {
    vector<pair<int,int>> up, vp;
    while(TOP[u]!=TOP[v]) {
        auto &path = D[TOP[u]] > D[TOP[v]] ? up : vp;
        auto &ver = D[TOP[u]] > D[TOP[v]] ? u : v;
        path.push_back({IN[TOP[ver]], IN[ver]});
        ver = P[TOP[ver]];
    }
    if(D[u] > D[v]) up.push_back({IN[v], IN[u]});
    else vp.push_back({IN[u], IN[v]});
    reverse(vp.begin(),vp.end());
    
    ll st=0;
    for(auto [l,r]:up) {
        st+=r-l+1;
        seg.update(l, r, -1);
        seg.update(l, l, st);
        seg.update(r+1, r+1, -st+(r-l+1));
    }
    for(auto [l,r]:vp) {
        seg.update(l,r,1);
        seg.update(l,l,st-1);
        seg.update(r+1,r+1, -st+1-(r-l+1));
        st+=r-l+1;
    }    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs1(), dfs2(), dfs3(TOP[1]=1);

    cin >> Q;
    for(int i=0,op,u,v,x;i<Q;i++) {
        cin >> op;
        if(op==1) cin >> u >> v, update(u, v);
        else cin >> x, cout << seg.query(1, IN[x]) << '\n';
    }
    return 0;
}