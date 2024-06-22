#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename node_t, typename f_merge>
struct SegmentTree {
    const int n, lg, sz;
    const node_t e;
    vector<node_t> tree;
    f_merge mrg;
    SegmentTree(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), e(e), tree(sz<<1,e) {}
    void bld() { for(int i=sz-1;i>=1;i--) tree[i]=mrg(tree[i*2],tree[i*2+1]); }
    void upd(int i, const node_t& v) {
        tree[i|=sz]+=v;
        while(i/=2) tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    node_t& operator [](int i) {return tree[sz|i]; }
    node_t qry(int l, int r) const {
        node_t ret=e;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=mrg(tree[l++],ret);
            if(~r&1) ret=mrg(ret,tree[r--]);
        }
        return ret;
    }
};

struct Point {
    int x, y;
    bool operator<(Point a) {return y==a.y ? x<a.x : y<a.y;}
};

const int MOD=1e9+7, H=200'000, M=400'000;
vector<int> X[404040];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0,x,y;i<n;i++) {
        cin >> x >> y;
        X[-y+H].push_back(x+H);
    }

    SegmentTree<ll,plus<ll>> seg(M,0);

    ll ans=0;
    for(int i=0;i<=M;i++) {
        for(int j:X[i]) ans=(ans+seg.qry(0,j-1)*seg.qry(j+1,400'000)%MOD)%MOD;
        for(int j:X[i]) seg.upd(j,1);
    }
    cout << ans;
    return 0;
}