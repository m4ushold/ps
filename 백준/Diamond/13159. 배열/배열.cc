#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename T>
struct SplayTree {
    struct Node {
        Node *l, *r, *p;
        int cnt, mn, mx, h;
        ll sum;
        T val;
        bool inv;
        Node(T val) : l(0), r(0), p(0), val(val), cnt(0), inv(0),mn(0),mx(0),sum(0),h(1) {}
        ~Node(){
            if(l) delete l;
            if(r) delete r;
        }
    } *tree;
    Node *vec[303030];
    int n, wait, cnt;

    SplayTree(vector<T> v) : n(v.size()), wait(sqrt(n)), cnt(0) {
        vec[0]=new Node(0), vec[n+1]=new Node(0);
        for(int i=1;i<=n;i++) vec[i]=new Node(v[i-1]);
        for(int i=1;i<=n;i++) vec[i]->p=vec[i-1], vec[i]->r=vec[i+1];
        vec[0]->r=vec[1], vec[n+1]->p=vec[n];
        for(int i=n+1;i>=0;i--) update(vec[i]);
        tree=vec[0];
    }
    
    void prop(Node *x) {
        if (!x->inv) return;
        swap(x->l, x->r);
        x->inv=0;
        if(x->l) x->l->inv^=1;
        if(x->r) x->r->inv^=1;
    }
    
    void update(Node *x) {
        if(!x) return;
        x->cnt = 1;
        x->mn=x->mx=x->sum=x->val;
        x->h = 0;
        if(x->l) x->cnt+=x->l->cnt, x->mn=min(x->mn,x->l->mn), x->mx=max(x->mx, x->l->mx), x->sum+=x->l->sum, x->h=max(x->h, x->l->h);
        if(x->r) x->cnt+=x->r->cnt, x->mn=min(x->mn,x->r->mn), x->mx=max(x->mx, x->r->mx), x->sum+=x->r->sum, x->h=max(x->h, x->r->h);
        x->h+=1;
    }

    void rotate(Node *x) {
        if(!x) return;
        Node *p=x->p, *b=0;
        prop(p), prop(x);
        if(!p) return;
        if(x==p->l) p->l=b=x->r, x->r=p;
        else p->r=b=x->l, x->l=p;
        x->p=p->p, p->p=x;
        if(b) b->p=p;

        (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
        update(p), update(x);
    }
    void splay_max() {
        Node *x = tree;
        while(x->l || x->r) {
            if(x->l && x->l->h+1 == x->h) x=x->l;
            else x=x->r;
        }
        internal_splay(x);
    }
    
    void splay(Node *x) {
        if(++cnt == wait) {
            splay_max();
            cnt=0;
        }
        internal_splay(x);
    }

    void internal_splay(Node *x) {
        if(!x) return;
        while(x->p) {
            Node *p=x->p, *g=p->p;
            if(g) rotate((x==p->l) == (p==g->l) ? p : x);
            rotate(x);
        }
        prop(x);
    }

    void kth(int k) {
        Node *x=tree;
        if(!x || k>n) return;
        prop(x);
        while(1) {
            while(x->l && x->l->cnt > k) x=x->l, prop(x);
            if(x->l) k-=x->l->cnt;
            if(!k--) break;
            x=x->r;
            prop(x);
        }
        splay(x);
    }

    Node* gather(int l, int r) {
        kth(l-1);
        Node *x = tree;
        tree=x->r, tree->p=0;
        kth(r-l+1);
        x->r=tree, tree->p=x;
        tree=x;
        return tree->r->l;
    }

    void rev(int l, int r) {
        if(l>=r) return;
        Node *x=gather(l,r);
        if(!x) return;
        x->inv^=1;
    }
    void qry(int l, int r) {
        Node *x=gather(l,r);
        cout << x->mn << ' ' << x->mx << ' ' << x->sum << '\n';
    }
    
    int mod(int k, int m) { return (k%m+m)%m; }
    void shift(int l, int r, int k) {
        k=mod(k,r-l+1), rev(l,r), rev(l,l+k-1), rev(l+k,r);
    }

    void f(Node *x) {
        prop(x);
        if(x->l) f(x->l);
        if(x->val) cout << x->val << ' ';
        if(x->r) f(x->r);
    }
    void p() {
        f(tree), cout << '\n';
    }
};

int mod(int x, int m) {
    return (x%m+m)%m;
}

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
        else if(a==2) cin >> r >> x, x=mod(x,r-l+1), tree.qry(l,r), tree.rev(l,r), tree.rev(l,l+x-1), tree.rev(l+x,r);
        else if(a==3) tree.kth(l), cout << tree.tree->val << '\n';
        else tree.splay(tree.vec[l]), cout << tree.tree->l->cnt << '\n';
    }
    tree.p();
    return 0;
}