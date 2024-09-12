#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    static const int sz=1<<18;
    vector<int> T[sz<<1];
    void bld() { 
        for(int i=sz-1;i>=1;i--) {
            T[i].resize(T[i*2].size()+T[i*2+1].size());
            merge(T[i*2].begin(),T[i*2].end(), T[i*2+1].begin(),T[i*2+1].end(), T[i].begin());
        }
    }
    vector<int>& operator[](int i) {return T[sz|i];}
    ll qry(int l, int r, int c) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=upper_bound(T[l].begin(),T[l].end(),c)-lower_bound(T[l].begin(),T[l].end(),c), l++;
            if(~r&1) ret+=upper_bound(T[r].begin(),T[r].end(),c)-lower_bound(T[r].begin(),T[r].end(),c), r--;
        }
        return r-l+1-ret;
    }
} seg;

int N, IN[202020], OUT[202020], C[202020], X[202020], DP[202020], P[202020];
vector<int> G[202020];

void dfs(int v=1, int p=-1) {
    static int pv=0;
    X[v]^=C[v], IN[v]=++pv;
    for(int i:G[v]) if(i!=p) X[i]^=X[v], dfs(i,v), P[i]=v;
    OUT[v]=pv;
}

int has(int v, int c) {
    return seg.qry(IN[v], OUT[v], c);
}

int mex(set<int> &s) {
    int i=0;
    while(s.count(i)) i++;
    return i;
}

void dp(int v=1, int p=0) {
    int x=0;
    for(int i:G[v]) if(i!=p) dp(i,v), x^=DP[i];
    set<int> s;
    if(!C[v]) s.insert(x);
    for(int i:G[v]) if(i!=p) if(has(i,X[P[v]])) s.insert(DP[i]^x);
    DP[v]=mex(s);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> C[i];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs();
    for(int i=1;i<=N;i++) seg[IN[i]].push_back(X[i]);
    seg.bld(), dp();
    cout << (DP[1]?"kidw0124":"eoaud0108");
    return 0;
}