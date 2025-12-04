#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, sz;
    vector<S> T;
    segtree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void set(int i, S x) {
        T[i|=sz] = x;
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    void add(int i, S x) {
        T[i|sz] = op(T[i|=sz], x);
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    S qry(int l, int r) {
        S L=e(), R=e();
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) L=op(L,T[l++]);
            if(~r&1) R=op(T[r--],R);
        }
        return op(L,R);
    }
};

constexpr int mod = 1e9+7;

struct node {
    ll len,r,o,c,k,ro,roc,rock,oc,ock,ck,id;
    node(char ch, int f=0) : len(1), id(f) {
        r=o=c=k=ro=roc=rock=oc=ock=ck=0;
        if(ch == 'R') r=1;
        else if(ch == 'O') o=1;
        else if(ch == 'C') c=1;
        else if(ch == 'K') k=1;
    }
};

ll T[1<<18];

node op(node a, node b) {
    if(a.id) return b;
    if(b.id) return a;
    node c('a');
    c.len = a.len+b.len;

    c.r = (a.r + b.r * T[a.len] % mod) % mod;
    c.ro = (a.ro + b.ro * T[a.len] % mod + a.r * b.o % mod) % mod;
    c.roc = (a.roc + b.roc * T[a.len] % mod + a.r * b.oc % mod + a.ro * b.c % mod) % mod;
    c.rock = (a.rock + b.rock * T[a.len] % mod + a.r * b.ock % mod + a.ro * b.ck % mod + a.roc * b.k % mod) % mod;

    c.o = a.o + b.o, c.c = a.c + b.c, c.k = a.k + b.k;
    c.oc = (a.oc + b.oc + a.o * b.c % mod) % mod;
    c.ock = (a.ock + b.ock + a.o * b.ck % mod + a.oc * b.k % mod) % mod;
    c.ck = (a.ck + b.ck + a.c * b.k % mod) % mod;
    return c;
}

node e() {return node('a', 1);}

void sol(int tc) {
    T[0]=1;
    for(int i=1;i<1<<18;i++) T[i]=T[i-1]*2%mod;

    int n; cin >> n;
    string s; cin >> s;
    segtree<node, op, e> seg(n);
    for(int i=0;i<n;i++) seg.set(i, node(s[i]));

    int q; cin >> q;
    for(int i=0;i<q;i++) {
        int op,j,l,r; cin >> op;
        char c;
        if(op == 1) {
            cin >> j >> c;
            seg.set(j-1, node(c));
        } else {
            cin >> l >> r;
            cout << seg.qry(l-1,r-1).rock << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}