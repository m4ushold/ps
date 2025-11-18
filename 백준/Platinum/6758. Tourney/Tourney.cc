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

pll op(pll a, pll b) {return max(a,b);}
pll e() {return pll(-1,-1);}

void sol(int tc) {
    int n,q; cin >> n >> q;
    n = 1<<n;
    SegTree<pll,op,e> seg(n);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        seg.upd(i, {x,i});
    }
    for(int i=0;i<q;i++) {
        char op; cin >> op;
        if(op == 'R') {
            int i,j; cin >> i >> j;
            --i;
            seg.upd(i,{j,i});
        } else if(op == 'W') {
            cout << seg.T[1].second+1 << endl;
        } else {
            int j; cin >> j;
            --j;
            j|=seg.sz;
            int cnt=0;
            while(j/2 && seg.T[j/2].first == seg.T[j].first) j/=2, cnt++;
            cout << cnt << endl;
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