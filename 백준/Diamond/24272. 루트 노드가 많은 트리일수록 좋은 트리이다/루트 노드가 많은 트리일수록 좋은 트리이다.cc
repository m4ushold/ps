#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct LazySeg {
    const static int sz=1<<17;
    int T[sz<<1], L[sz<<1];
    void update(int l, int r, int v, int i=1, int s=0, int e=sz-1) {
        if(r<s || e<l) return;
        else if(l<=s && e<=r) L[i]+=v;
        else {
            int m=s+e>>1;
            update(l,r,v,i*2,s,m), update(l,r,v,i*2+1,m+1,e);
        }
        if(L[i]) T[i]=e-s+1;
        else if(s==e) T[i]=0;
        else T[i]=T[i*2]+T[i*2+1];
    }
} seg;

int N, Q, IN[101010], OUT[101010], P[101010];
vector<int> G[101010];

void dfs(int v=1, int p=-1) {
    static int pv=0;
    IN[v]=++pv;
    for(int i:G[v]) if(i!=p) dfs(i,v), P[i]=v;
    OUT[v]=pv;
}

string f(int u, int v, string d) {
    if(d=="--" || u<v) return d;
    if(d=="->") return "<-";
    return "->";
}

void connect(int u, int v, string d) {
    if((d=="->" && P[u]==v) ||(d=="<-" && P[v]==u)) { // upward
        if(P[u]==v) swap(u,v);
        seg.update(1,IN[v]-1,1), seg.update(OUT[v]+1,N,1);
    } else if(d!="--") { // downward
        if(P[u]==v) swap(u,v);
        seg.update(IN[v], OUT[v], 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<tuple<int, string, int>> v(N-1);
    map<pair<int,int>,string> edge;
    for(auto &[u,d,v]:v) {
        cin >> u >> d >> v;
        edge[{min(u,v),max(u,v)}]=f(u,v,d);
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs();
    for(auto [u,d,v]:v) {
        connect(u,v,d);
    }

    cin >> Q, v.resize(Q);
    for(auto &[u,d,v]:v) {
        cin >> u >> d >> v;
        // erase before state
        int uu=min(u,v), vv=max(u,v);
        if(edge[{uu,vv}] == "->") {
            if(P[uu]==vv) seg.update(1,IN[uu]-1,-1), seg.update(OUT[uu]+1,N,-1);
            else seg.update(IN[vv],OUT[vv],-1);
        } else if(edge[{uu,vv}] == "<-") {
            if(P[uu]==vv) seg.update(IN[uu],OUT[uu],-1);
            else seg.update(1,IN[vv]-1,-1), seg.update(OUT[vv]+1,N,-1);
        }

        connect(u,v,d);
        edge[{uu,vv}]=f(u,v,d);
        cout << N-seg.T[1] << '\n';
    }
    return 0;
}