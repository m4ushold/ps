#include <bits/stdc++.h>
using namespace std;

int N, Q, IN[1010101], OUT[1010101];
vector<int> G[1010101];

constexpr int sz=1<<20;
struct {
    int MN[sz<<1], MX[sz<<1], L[sz<<1];
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        MN[i] += L[i];
        MX[i] += L[i];
        if(s^e) for(int j:{i<<1,i<<1|1}) L[j]+=L[i];
        L[i]=0;
    }
    void upd(int l, int r, int x, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(e<l || r<s) return ;
        else if(l<=s && e<=r) {L[i]+=x, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l, r, x, i<<1, s, m), upd(l,r,x,i<<1|1,m+1,e);
        MN[i] = min(MN[i<<1], MN[i<<1|1]);
        MX[i] = max(MX[i<<1], MX[i<<1|1]);
    }
    int mn(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(e<l || r<s) return 1e9;
        else if(l<=s && e<=r) return MN[i];
        int m=s+e>>1;
        return min(mn(l, r, i<<1, s, m), mn(l, r, i<<1|1,m+1,e));
    }
    int mx(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(e<l || r<s) return 0;
        else if(l<=s && e<=r) return MX[i];
        int m=s+e>>1;
        return max(mx(l, r, i<<1, s, m), mx(l, r, i<<1|1,m+1,e));
    }
} seg;

void dfs(int v=1, int p=-1) {
    static int pv=0;
    IN[v]=++pv;
    for(int i:G[v]) if(i!=p) dfs(i,v);
    OUT[v]=pv;
}

void sol() {
    memset(IN, 0, sizeof(IN)), memset(OUT, 0, sizeof(OUT));
    for(int i=0;i<1010101;i++) G[i].clear();
    cin >> N;
    for(int i=2,p;i<=N;i++) cin >> p, G[p].push_back(i);
    dfs();
    for(int i=1,x;i<=N;i++) cin >> x, seg.upd(IN[i], IN[i], x);
    cin >> Q;
    for(int i=0,a,b;i<Q;i++) {
        char op; cin >> op;
        if(op=='R') cin >> a >> b, seg.upd(IN[a], OUT[a], b);
        else cin >> a, cout << seg.mx(IN[a], OUT[a])-seg.mn(IN[a], OUT[a]) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}