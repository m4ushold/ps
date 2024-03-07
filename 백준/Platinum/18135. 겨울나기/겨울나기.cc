#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    static const int sz=1<<20;
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

int M[2020202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    for(int i=1;i<=q;i++) {
        int x,y,z; cin >> x >> y >> z;
        for(int j=x;j<=y;j++) M[j]=i;
        seg.T[seg.sz|i]=z;
    }
    seg.build();
    
    int a,x,y,z; 
    while(cin >> a >> x >> y && a) {
        x=M[x], y=M[y];
        if(a&1) {
            if(x<=y) cout << seg.sumQuery(x,y) << '\n';
            else cout << seg.sumQuery(1,y)+seg.sumQuery(x,q) << '\n';
        }
        else {
            cin >> z;
            if(x<=y) seg.addQuery(x,y,z);
            else seg.addQuery(1,y,z), seg.addQuery(x,q,z);
        }
    }
    return 0;
}