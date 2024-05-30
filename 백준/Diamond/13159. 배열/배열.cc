#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template <typename T> struct SplayTree {
    struct Node {
        int l, r, p, cnt, inv;
        ll mn, mx, sum;
        T val;
        Node() : l(-1), r(-1), p(-1), cnt(0), inv(0), mn(0), mx(0), sum(0) {}
        // Node(T val) : val(val), l(-1), r(-1), p(-1), cnt(0), inv(0) {}
    };

    int n, sz, root;
    vector<Node> t;

    SplayTree(vector<T> v) : n(v.size()), t(n+2), sz(n+2), root(0) {
        t[0].r=1, t[0].cnt=n+1, t[n+1].p=n, t[n+1].cnt=1;
        for(int i=1;i<=n;i++) t[i].mn=t[i].mx=t[i].sum=t[i].val=v[i-1], t[i].p=i-1, t[i].r=i+1, t[i].cnt=n-i+1;
        for(int i=n+1;i>=0;i--) upd(i);
    }
    
    void prop(int x) {
        if(!t[x].inv) return;
        swap(t[x].l, t[x].r);
        t[x].inv=0;
        if(t[x].l>=0) t[t[x].l].inv=!t[t[x].l].inv;
        if(t[x].r>=0) t[t[x].r].inv=!t[t[x].r].inv;
    }
    void upd(int x) {
        t[x].cnt=1, t[x].mn=t[x].mx=t[x].sum=t[x].val;
        if(t[x].l>=0) t[x].cnt += t[t[x].l].cnt, t[x].mn=min(t[x].mn, t[t[x].l].mn), t[x].mx=max(t[x].mx, t[t[x].l].mx), t[x].sum+=t[t[x].l].sum;
        if(t[x].r>=0) t[x].cnt += t[t[x].r].cnt, t[x].mn=min(t[x].mn, t[t[x].r].mn), t[x].mx=max(t[x].mx, t[t[x].r].mx), t[x].sum+=t[t[x].r].sum;
    }
    void rotate(int x) {
        int p=t[x].p, b;
        prop(p), prop(x);
        if(p==-1) return;
        if(x==t[p].l) t[p].l=b=t[x].r, t[x].r=p;
        else t[p].r=b=t[x].l, t[x].l=p;
        t[x].p=t[p].p, t[p].p=x;
        if(b>=0) t[b].p=p;

        (t[x].p>=0 ? p==t[t[x].p].l ? t[t[x].p].l : t[t[x].p].r : root) = x;
        upd(p), upd(x);
    }
    void splay(int x) {
        while(t[x].p>=0) {
            int p=t[x].p, g=t[p].p;
            if(g>=0) rotate((x==t[p].l) == (p==t[g].l) ? p : x);
            rotate(x);
        }
        prop(x);
    }

    void kth(int k) {
        int x=root; prop(x);
        while(1) {
            while(t[x].l>=0 && t[t[x].l].cnt > k) x=t[x].l, prop(x);
            if(t[x].l>=0) k-=t[t[x].l].cnt;
            if(!k--) break;
            x=t[x].r, prop(x);
        }
        splay(x);
    }

    int gather(int l, int r) {
        kth(l-1);
        int x=root;
        root=t[x].r, t[root].p=-1;
        kth(r-l+1);
        t[x].r=root, t[root].p=x, root=x;
        return t[t[root].r].l;
    }

    void rev(int l, int r) {
        if(l>r) return;
        int x=gather(l,r);
        t[x].inv=!t[x].inv;
    }

    int mod(int x, int m) { return (x%m+m)%m; }
    void shift(int l, int r, int x) {
        x=mod(x,r-l+1), rev(l,r), rev(l,l+x-1), rev(l+x,r);
    }

    void qry(int l, int r) {
        int x=gather(l,r);
        cout << t[x].mn << ' ' << t[x].mx << ' ' << t[x].sum << '\n';
    }

    void dfs(int x) {
        prop(x);
        if(t[x].l>=0) dfs(t[x].l);
        if(t[x].val) cout << t[x].val << ' ';
        if(t[x].r>=0) dfs(t[x].r);
    }

    void print() {
        dfs(root);
        cout << '\n';
    }
};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    SplayTree<int> tree(v);

    for(int i=0,a,l,r,x,j;i<q;i++) {
        cin >> a >> l;
        if(a==1) cin >> r, tree.qry(l,r), tree.rev(l,r);
        else if(a==2) cin >> r >> x, tree.qry(l,r), tree.shift(l,r,x);
        else if(a==3) tree.kth(l), cout << tree.t[tree.root].val << '\n';
        else tree.splay(l), cout << tree.t[tree.t[tree.root].l].cnt << '\n';
    }
    tree.print();
    return 0;
}