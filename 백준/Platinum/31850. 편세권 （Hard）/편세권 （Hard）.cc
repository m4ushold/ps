#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename node_t>
struct SegmentTree {
    const int n, lg, sz;
    const node_t e;
    vector<node_t> tree;
    SegmentTree(int n, const node_t &e) : n(n), lg(__lg(n)+1), sz(1<<lg), e(e), tree(sz<<1,e) {}
    node_t mrg(node_t a, node_t b) { return max(a,b); }
    void upd(int i, const node_t& v) {
        tree[i|=sz]=v;
        while(i/=2) tree[i]=mrg(tree[i*2],tree[i*2+1]);
    }
    node_t qry(int l, int r) {
        node_t ret=e;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=mrg(tree[l++],ret);
            if(~r&1) ret=mrg(ret,tree[r--]);
        }
        return ret;
    }
};

int N, M, R, C;
vector<int> X[505050];
struct room {
    ll x,y,p;
    bool operator<(room a) {
        return x==a.x ? y < a.y : x < a.x;
    }
};

ll f(vector<room>& r) {
    ll mx=numeric_limits<ll>::max(), dap=mx, e=numeric_limits<ll>::min(), p=1;
    SegmentTree<ll> s1(M,e), s2(M,e);
    for(room i:r) {
        while(p<=i.x) {
            for(int j:X[p]) s1.upd(j, p+j), s2.upd(j,p-j);
            p++;
        }
        ll a=s1.qry(1,i.y), b=s2.qry(i.y,M), dist=mx;
        if(a!=e) dist=min(dist,i.x+i.y-a);
        if(b!=e) dist=min(dist,i.x-i.y-b);
        if(dist!=mx) dap=min(dap, i.p*dist);
    }
    return dap;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R >> C;
    vector<room> r(R);
    for(auto &i:r) cin >> i.x >> i.y >> i.p;
    for(int i=0,a,b;i<C;i++) cin >> a >> b, X[a].push_back(b);
    sort(r.begin(),r.end());
    ll dap=f(r);

    for(auto &i:r) i.x=N-i.x+1;
    for(int i=1;i<=N/2;i++) swap(X[i],X[N-i+1]);
    reverse(r.begin(),r.end());

    cout << min(dap,f(r));
    return 0;
}