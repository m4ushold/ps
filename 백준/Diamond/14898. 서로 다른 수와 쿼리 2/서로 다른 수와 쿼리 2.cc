#include <bits/stdc++.h>
using namespace std;

struct PST {
    struct Node {
        int l, r, v;
        Node() {l=r=v=0;}
    };
    int sz;
    vector<int> root;
    vector<Node> T;
    PST() : T(1) {
        root.reserve(22*1e6);
        T.reserve(22*1e6);
    }
    int upd(int x, int v) {
        root.push_back(T.size()), T.push_back(Node());
        update(root[root.size()-2], root.back(), 1, sz, x, v);
        return root.back();
    }
    void update(int prv, int now, int s, int e, int x, int v) {
        if(s==e) {T[now].v = v; return;}
        int m=s+e>>1;
        if(x<=m) {
            T[now].l = T.size(), T.push_back(Node());
            T[now].r = T[prv].r;
            update(T[prv].l, T[now].l, s, m, x, v);
        } else {
            T[now].r = T.size(), T.push_back(Node());
            T[now].l = T[prv].l;
            update(T[prv].r, T[now].r, m+1, e, x, v);
        }
        T[now].v = T[T[now].l].v + T[T[now].r].v;
    }
    int query(int i, int s, int e, int l, int r) {
        if(!i || e<l || s>r) return 0;
        if(l<=s && e<=r) return T[i].v;
        int m=s+e>>1;
        return query(T[i].l,s,m,l,r)+query(T[i].r,m+1,e,l,r);
    }
} pst;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n), prv(n, -1), idx(n+1);
    for(int &i:v) cin >> i;
    vector<int> c(v.begin(),v.end());
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(int &i:v) i = lower_bound(c.begin(),c.end(),i)-c.begin();
    pst.sz=n;

    for(int i=1;i<=n;i++) {
        int x=v[i-1], j;
        j=pst.upd(i, 1);
        if(prv[x]!=-1) j=pst.upd(prv[x], 0);
        prv[x]=i, idx[i]=j;
    }

    int Q, ans=0; cin >> Q;
    for(int i=0,x,l,r;i<Q;i++) {
        cin >> x >> r;
        l=x+ans;
        ans = pst.query(idx[r], 1, n, l, r);
        cout << ans << '\n';
    }
    return 0;
}