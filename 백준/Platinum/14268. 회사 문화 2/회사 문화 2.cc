#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    static const int sz=1<<19;
    ll T[sz<<1], L[sz<<1];
    void build() { for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1]; }
    void push(int node, int s, int e) {
        if(L[node]==0) return;
        T[node]+=(e-s+1)*L[node];
        if(s!=e) L[node*2]+=L[node], L[node*2+1]+=L[node];
        L[node]=0;
    }
    void addQuery(int l, int r, int v, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        addQuery(l,r,v,node*2,s,m), addQuery(l,r,v,node*2+1,m+1,e);
        T[node]=T[node*2]+T[node*2+1];
    }
    ll sumQuery(int l, int r, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return sumQuery(l,r,2*node,s,m)+sumQuery(l,r,2*node+1,m+1,e);
    }
} seg;

int N, M, IN[505050], OUT[505050];
vector<int> G[505050];

void dfs(int v=1) {
    static int c=0;
    IN[v]=++c;
    for(int i:G[v]) dfs(i);
    OUT[v]=c;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1,p;i<=N;i++) {
        cin >> p;
        if(p>0) G[p].push_back(i);
    }
    dfs();
    for(int i=0,o,a,x;i<M;i++) {
        cin >> o >> a;
        if(o&1) cin >> x, seg.addQuery(IN[a], OUT[a], x);
        else cout << seg.sumQuery(IN[a],IN[a]) << '\n';
    }
    return 0;
}