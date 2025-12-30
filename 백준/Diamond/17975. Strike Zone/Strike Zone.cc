#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using tpl=array<ll,3>;

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
    S qry(int l, int r) {
        S L=e(), R=e();
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) L=op(L,T[l++]);
            if(~r&1) R=op(T[r--],R);
        }
        return op(L,R);
    }
};

struct S {
    ll l,r,sum,mx;
    S(ll a, ll b, ll c, ll d) {l=a,r=b,sum=c,mx=d;}
    S(ll x=0) : S(x, x, x, x) {}
};
S op(S a, S b) {
    return S(max(a.l, a.sum+b.l), max(b.r,a.r+b.sum),a.sum+b.sum,max({a.mx,b.mx,a.r+b.l}));
}
constexpr ll M = LLONG_MIN/2;
S e() {return S(0);}

void sol(int tc) {
    int n1,n2; cin >> n1;
    vector<int> x,y;
    vector<tpl> pts;
    for(int i=0,a,b;i<n1;i++) {
        cin >> a >> b;
        x.push_back(a), y.push_back(b);
        pts.push_back({a,b,1});
    }
    cin >> n2;
    for(int i=0,a,b;i<n2;i++) {
        cin >> a >> b;
        x.push_back(a), y.push_back(b);
        pts.push_back({a,b,-1});
    }
    int c1,c2; cin >> c1 >> c2;
    prs(x), prs(y);
    sort(all(pts));
    
    segtree<S,op,e> seg(y.size());
    for(auto &[a,b,c]:pts) {
        a=lower_bound(all(x),a)-x.begin();
        b=lower_bound(all(y),b)-y.begin();
        c=c==1?c1:-c2;
    }

    int n = x.size();
    ll mx=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            seg.set(pts[j][1], pts[j][2]);
            mx=max(mx, seg.qry(0,y.size()-1).mx);
        }
        for(int j=i;j<n;j++) seg.set(pts[j][1], e());
    }
    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}