#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
using node_t=array<ll,3>;

struct SegTree {
    static const int sz=1<<19;
    int L[sz<<1];
    node_t T[sz<<1];
    node_t merge(node_t a, node_t b) { return node_t{a[0]|b[0], (a[0]&b[0])|a[1]|b[1], (a[0]&b[1])|(a[1]&b[0])|a[2]|b[2]}; }
    ll ro(ll n, int x) { return (n<<x)|(n>>(64-x)); }
    node_t ro(node_t n, int x) { return node_t{ro(n[0],x), ro(n[1],x), ro(n[2],x)}; }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=merge(T[i*2],T[i*2+1]); }
    void push(int node, int s, int e) {
        if(L[node]==0) return;
        T[node]=ro(T[node],L[node]);
        if(s!=e) L[node*2]=(L[node*2]+L[node])%64, L[node*2+1]=(L[node*2+1]+L[node])%64;
        L[node]=0;
    }
    void upd(int l, int r, int v, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=merge(T[node*2],T[node*2+1]);
    }
    node_t qry(int l, int r, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return node_t{0,0,0};
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return merge(qry(l,r,2*node,s,m),qry(l,r,2*node+1,m+1,e));
    }
} seg;

vector<array<int,3>> X[64];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<64;i++) for(int j=i+1;j<64;j++) for(int k=j+1;k<64;k++) {
        X[(i^j^k)].push_back(array<int,3>{i,j,k});
    }

    int n, q; cin >> n >> q;
    for(int i=1,a;i<=n;i++) cin >> a, seg.T[seg.sz|i]=node_t{1ULL<<a,0,0};
    seg.build();

    for(int i=0,a,l,r,x;i<q;i++) {
        cin >> a >> l >> r >> x;
        if(~a&1) seg.upd(l,r,x);
        else {
            auto [s,d,t]=seg.qry(l,r);
            int f = ((d&~(1ULL<<x)) && (s&(1ULL<<x))) || (t&(1ULL<<x));
            if(!f) for(auto b:X[x]) f |= (s&(1ULL<<b[0])) && (s&(1ULL<<b[1])) && (s&(1ULL<<b[2]));
            cout << f << '\n';
        }
    }
    return 0;
}