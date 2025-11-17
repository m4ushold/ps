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

int op(int a, int b) {return a+b;}
int e() {return 0;}

void sol(int tc) {
    int n;
    while(cin >> n && n) {
        vector<int> v(n);
        for(int &i:v) cin >> i;
        ll cnt=0;
        SegTree<int,op,e> seg(n+1);
        for(int i:v) {
            cnt += seg.qry(i,n);
            seg.upd(i, 1);
        }
        if(cnt&1) cout << "Marcelo" << endl;
        else cout << "Carlos" << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}