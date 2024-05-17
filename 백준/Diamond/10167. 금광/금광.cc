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
    void upd(int i, const int v) {
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

struct Gold { 
    int x, y, w;
    bool operator<(Gold &a) { return y==a.y ? x<a.x : y<a.y; }
};

struct Node { 
    ll sum, l, r, mx; 
    void operator+=(int v) {sum+=v, l+=v, r+=v, mx+=v;}
};

struct Mrg {
    Node operator() (Node& a, Node& b) const {
        return Node{
            a.sum+b.sum, 
            max(a.l,a.sum+b.l), 
            max(b.r,b.sum+a.r), 
            max({a.r+b.l,a.mx,b.mx,a.sum+b.sum})
        };
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<Gold> g(n);
    vector<int> x, y;
    for(auto &i:g) cin >> i.x >> i.y >> i.w, x.push_back(i.x), y.push_back(i.y);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());
    transform(g.begin(),g.end(), g.begin(), [&](Gold i) {
        return Gold {
            (int)(lower_bound(x.begin(),x.end(),i.x)-x.begin()),
            (int)(lower_bound(y.begin(),y.end(),i.y)-y.begin()),
            i.w
        };
    });
    sort(g.begin(),g.end());

    ll dap=0;
    for(int i=0;i<n;i++) {
        if(i && g[i-1].y==g[i].y) continue;
        SegmentTree<Node,Mrg> seg(2*n,Node{0,0,0,0});
        for(int j=i;j<n;j++) {
            seg.upd(g[j].x, g[j].w);
            if(j==n-1 || g[j].y!=g[j+1].y) dap=max(dap,seg.tree[1].mx);
        }
    }
    cout << dap;
    return 0;
}