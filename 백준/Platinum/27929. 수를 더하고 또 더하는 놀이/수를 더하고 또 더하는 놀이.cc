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
    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(T[i*2]>=k) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return i^sz;
    }
};

ll op(ll a, ll b) {return a+b;}
ll e() {return 0;}

void sol(int tc) {
    int n,m; cin >> n >> m;
    
    vector<pll> v, qry(m);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        v.push_back({x,0});
    }
    ll s=0;
    for(int i=1;i<=m;i++) {
        auto &[x,y] = qry[i-1];
        cin >> x >> y;
        if(x==1) v.push_back({y-s, i});
        else if(x==2) s+=y;
    }
    sort(all(v));
    SegTree<ll,op,e> seg(v.size()), cnt(v.size());
    map<int,int> rid;
    for(int j=0;j<v.size();j++) {
        auto [x,i] = v[j];
        if(i==0) seg.upd(j,x), cnt.upd(j,1);
        else rid[i]=j;
    }
    int asdf = v.size()-1;
    s=0;
    for(int i=1;i<=m;i++) {
        auto [op,a] = qry[i-1];
        if(op==1) {
            int j = rid[i];
            seg.upd(j,a-s);
            cnt.upd(j,1);
        } else if(op == 2) {
            s+=a;
        } else if(op == 3) {
            int j = cnt.kth(cnt.T[1]-a+1);
            cout << seg.qry(j, asdf) + a*s << ' ';
        } else {
            int j = cnt.kth(a);
            cout << seg.qry(0,j) + cnt.qry(0,j)*s << ' ';
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}