#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct LazySeg {
    const static int sz=1<<17;
    ll T[sz<<1], L[sz<<1];
    ll& operator[](int i) {return T[sz|i];}
    LazySeg() {for(int i=0;i<sz*2;i++) T[i]=LLONG_MIN;}
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=max(T[i*2],T[i*2+1]); }
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i]+=L[i];
        if(s!=e) L[i*2]+=L[i], L[i*2+1]+=L[i];
        L[i]=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=max(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return LLONG_MIN;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return max(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} seg;

ll N, W[101010], IN[101010], OUT[101010], P[101010];
vector<int> G[101010];

void dfs(int v, int p=-1) {
    static int pv=0;
    IN[v]=++pv;
    for(int i:G[v]) if(i!=p) W[i]+=W[v], dfs(i,v), P[i]=v;
    OUT[v]=pv;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    int rt=1;
    for(int i=1,p;i<=N;i++) {
        cin >> p;
        if(p) G[p].push_back(i);
        else rt=i;
    }
    for(int i=1,p;i<=N;i++) cin >> W[i];
    dfs(rt);
    for(int i=1,p;i<=N;i++) seg.T[seg.sz|IN[i]] = W[i];
    seg.bld();
    
    int q; cin >> q;
    for(int i=1,a,b,c;i<=q;i++) {
        cin >> a >> b;
        if(a==1) {
            ll t=seg.qry(IN[b],IN[b]) - seg.qry(IN[P[b]], IN[P[b]]);
            cin >> c, seg.upd(IN[b], OUT[b], c-t);
        }
        else cout << seg.qry(IN[b], OUT[b])-seg.qry(IN[b],IN[b]) << '\n';
    }

    return 0;
}