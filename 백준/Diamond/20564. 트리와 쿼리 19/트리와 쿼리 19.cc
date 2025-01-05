#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<19;
struct {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    ll qry(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} f, g;

struct HLD {
    int N, TOP[sz], P[sz], D[sz], SZ[sz], IN[sz], OUT[sz], C[sz];
    vector<int> G[sz];
    ll dap=0;
    void connect(int u, int v) {
        G[u].push_back(v);
    }
    void d1(int v=1, int p=-1) {
        for(int i:G[v]) D[i]=D[v]+1, P[i]=v, d1(i,v);
    }
    void d2(int v=1) {
        SZ[v]=1;
        for(int &i:G[v]) {
            d2(i), SZ[v]+=SZ[i];
            if(SZ[i]>SZ[G[v][0]]) swap(i,G[v][0]);
        }
    }
    void d3(int v) {
        static int pv=0; IN[v]=++pv;
        for(int i:G[v]) TOP[i]=(i==G[v][0] ? TOP[v] : i), d3(i);
        OUT[v]=pv;
    }
    
    void upd(int v) {
        C[v]^=1;

        if(!C[v]) {
            f.upd(IN[v], -1);
            for(int i=v;i;i=P[TOP[i]]) g.upd(IN[i],-D[i]);
		}
        ll res=0, p=0;
        for(int i=v;i;i=P[TOP[i]]) {
            res += g.qry(IN[TOP[i]], IN[i] - 1) + (f.qry(IN[i], OUT[i]) - p) * D[i];
            p = f.qry(IN[TOP[i]], OUT[TOP[i]]);
        }
		if(C[v]) {
            f.upd(IN[v], 1);
            for(int i=v;i;i=P[TOP[i]]) g.upd(IN[i],D[i]);
		}

        dap += (C[v]?1:-1) * res;
    }

    void init() {
        for(int i=1;i<=N;i++) if(C[i]) C[i]=0, upd(i);
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
        init();
    }
    ll ans() {
        return dap;
    }
} tree;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    tree.N=n;
    for(int i=1;i<=n;i++) cin >> tree.C[i];
    for(int i=2,a;i<=n;i++) cin >> a, tree.connect(a,i);
    
    tree.build();
    cout << tree.ans() << '\n';
    for(int i=0,x;i<q;i++) {
        cin >> x;
        tree.upd(x);
        cout << tree.ans() << '\n';
    }
    return 0;
}