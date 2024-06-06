#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename node_t, typename f_merge>
struct SegmentTree {
    const int n, lg, sz;
    const node_t e;
    vector<node_t> tree;
    f_merge mrg;
    SegmentTree(int n, const node_t &e=node_t()) : n(n), lg(__lg(n)+1), sz(1<<lg), e(e), tree(sz<<1,e) {}
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        SegmentTree<int,plus<int>> seg(n);
        vector<pair<int,int>> v(n);
        vector<int> x,y;
        for(auto &[a,b]:v) cin >> a >> b, x.push_back(a), y.push_back(b);
        sort(x.begin(),x.end()), sort(y.begin(),y.end());
        x.erase(unique(x.begin(),x.end()), x.end());
        y.erase(unique(y.begin(),y.end()), y.end());
        for(auto &[a,b]:v) {
            a=x.size()-(lower_bound(x.begin(),x.end(),a)-x.begin())-1;
            b=lower_bound(y.begin(),y.end(),b)-y.begin();
        }
        sort(v.begin(),v.end());

        ll dap=0;
        for(auto [a,b]:v) dap+=seg.qry(0,b), seg.upd(b,1);
        cout << dap << '\n';
    }
    return 0;
}