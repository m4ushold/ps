#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    static const int sz=1<<17;
    ll T[sz<<1], L[sz<<1];
    void init() { for(int i=0;i<sz*2;i++) L[i]=-1; }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1]; }
    void push(int node, int s, int e) {
        if(L[node]==-1) return;
        T[node]=(e-s+1)*L[node];
        if(s!=e) L[node*2]=L[node], L[node*2+1]=L[node];
        L[node]=-1;
    }
    void upd(int l, int r, int v, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=T[node*2]+T[node*2+1];
    }
    ll qry(int l, int r, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return qry(l,r,2*node,s,m)+qry(l,r,2*node+1,m+1,e);
    }
} seg;

int N, M, IN[101010], OUT[101010];
vector<int> G[101010];

void dfs(int v=1) {
    static int c=0;
    IN[v]=++c;
    for(int i:G[v]) dfs(i);
    OUT[v]=c;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,p;i<=N;i++) cin >> p, G[p].push_back(i);
    dfs();
    for(int i=1;i<=N;i++) seg.T[seg.sz|i]=1;
    seg.init(), seg.build();
    int q; cin >> q;
    for(int i=0,a,j;i<q;i++) {
        cin >> a >> j;
        if(a==1) seg.upd(IN[j]+1, OUT[j], 1);
        else if(a==2) seg.upd(IN[j]+1, OUT[j], 0);
        else cout << seg.qry(IN[j]+1, OUT[j]) << '\n';
    }
    return 0;
}