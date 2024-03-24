#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    static const int sz=1<<17;
    ll T[sz<<1], L[sz<<1];
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0,s,e;i<n;i++) {
        cin >> s >> e;
        ll l=seg.sumQuery(s,s), r=seg.sumQuery(e,e);
        seg.addQuery(s,s,-l), seg.addQuery(e,e,-r);
        seg.addQuery(s+1,e-1,1);
        cout << l+r << '\n';
    }
    return 0;
}