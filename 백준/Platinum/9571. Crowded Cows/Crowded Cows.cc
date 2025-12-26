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
        T[i|sz] += x;
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
    int n,d; cin >> n >> d;
    vector<pll> v(n);
    vector<int> vv;
    for(auto &[a,b]:v) cin >> a >> b, vv.push_back(a);
    sort(all(v)), sort(all(vv));
    segtree<int,op,e> seg(n);
    for(int i=0;i<n;i++) seg.set(i,v[i].second);

    int ans=0;
    for(int i=0;i<n;i++) {
        auto [x,h] = v[i];
        int l = lower_bound(all(vv),x-d)-vv.begin(), r = upper_bound(all(vv),x+d)-vv.begin()-1;
        if(seg.qry(l,i) >= 2*h && seg.qry(i,r) >= 2*h) ans++;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}