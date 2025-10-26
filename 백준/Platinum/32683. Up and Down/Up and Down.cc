#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct SegTree {
    int n, sz;
    vector<S> T;
    SegTree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void clear() {
        T.assign(2*sz,e());
    }
    void upd(int i, S x) {
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

int op(int a, int b) {return max(a,b);}
int e() {return 0;}

void sol(int tc) {
    int n; cin >> n;
    vector<int> v(n), l(n), r(n), a;
    for(int &i:v) cin >> i;
    a=v, prs(a);
    for(int &i:v) i = lower_bound(all(a),i)-a.begin();
    SegTree<int,op,e> seg(n);
    for(int i=0;i<n;i++) {
        l[i]=seg.qry(0,v[i]-1)+1;
        seg.upd(v[i],l[i]);
    }

    seg.clear();
    reverse(all(v));
    for(int i=0;i<n;i++) {
        r[i]=seg.qry(0,v[i]-1)+1;
        seg.upd(v[i],r[i]);
    }
    reverse(all(r));

    int mx=0;
    for(int i=0;i<n;i++) if(l[i]>1 && r[i]>1) mx=max(mx,l[i]+r[i]-1);
    cout << mx << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}