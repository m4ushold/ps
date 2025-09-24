#include <bits/stdc++.h>
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
    int lower(int idx, S x) {
        int l=idx,r=n;
        while(l<r) {
            int m=l+r>>1;
            if(qry(idx,m) > x) r=m;
            else l=m+1;
        }
        return r;
    }
    int upper(int idx, S x) {
        int l=1,r=idx;
        while(l<r) {
            int m=l+r+1>>1;
            if(qry(m,idx) > x) l=m;
            else r=m-1;
        }
        return l;
    }
    int find() {
        int i=1;
        while(i<sz) {
            if(T[i*2] > T[i*2+1]) i<<=1;
            else i=i<<1|1;
        }
        return i^sz;
    }
};

using S=ll;
S op(S a, S b) {return max(a,b);}
S e() {return -1;}

void sol(int tc) {
    int n,m; cin >> n >> m;
    SegTree<S,op,e> seg(n);
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        seg.upd(i,x);
    }

    for(int i=0;i<m;i++) {
        char op; int j,x; cin >> op >> j;
        ll l = seg.qry(1,j-1), r = seg.qry(j+1,n), p = seg.T[seg.sz | j];
        if(op=='L') {
            if(l < p) cout << j << '\n';
            else if(r < p) cout << seg.upper(j, p) << '\n';
            else {
                if(l<r) cout << seg.lower(j, l) << '\n';
                else cout << seg.upper(j, r) << '\n';
            }
        } else if(op == 'R') {
            if(r < p) cout << j << '\n';
            else if(l < p) cout << seg.lower(j, p) << '\n';
            else {
                if(l<r) cout << seg.lower(j, l) << '\n';
                else cout << seg.upper(j, r) << '\n';
            }
        } else cin >> x, seg.upd(j,x);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}