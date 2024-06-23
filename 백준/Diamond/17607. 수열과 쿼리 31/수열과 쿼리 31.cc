#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename T>
struct SplayTree {
    struct Node {
        Node *l, *r, *p;
        int cnt, lmx, rmx, mx;
        T val;
        bool inv;
        Node(T val) : l(0), r(0), p(0), val(val), cnt(0), inv(0), lmx(0),rmx(0),mx(0) {}
        ~Node(){
            if(l) delete l;
            if(r) delete r;
        }
        void prop() {
            if(!inv) return;
            swap(l,r), swap(lmx, rmx);
            inv=0;
            if(l) l->inv^=1;
            if(r) r->inv^=1;
        }
        void update() {
            prop();
            cnt=1, lmx=rmx=mx=val;
            if(l&&r) {
                l->prop(), r->prop();
                cnt += l->cnt + r->cnt;
                lmx = l->lmx + (l->cnt == l->lmx && val ? 1+r->lmx : 0);
                rmx = r->rmx + (r->cnt == r->rmx && val ? 1+l->rmx : 0);
                mx = max({l->mx, r->mx, val ? l->rmx+r->lmx+1 : 0});
            } else if(l) {
                l->prop();
                cnt += l->cnt;
                lmx = l->lmx + (l->cnt==l->lmx ? val : 0);
                rmx = val ? l->rmx+1 : 0;
                mx = max(l->mx, val ? l->rmx+1 : 0);
            } else if(r) {
                r->prop();
                cnt += r->cnt;
                lmx = val ? r->lmx+1 : 0;
                rmx = r->rmx + (r->cnt==r->rmx ? val : 0);
                mx=max(r->mx, val ? r->lmx+1 : 0);
            }
        }
    } *tree;
    Node *vec[303030];
    int n;

    SplayTree(vector<T> v) : n(v.size()) {
        vec[0]=new Node(0), vec[n+1]=new Node(0);
        for(int i=1;i<=n;i++) vec[i]=new Node(v[i-1]);
        for(int i=1;i<=n;i++) vec[i]->p=vec[i-1], vec[i]->r=vec[i+1];
        vec[0]->r=vec[1], vec[n+1]->p=vec[n];
        for(int i=n+1;i>=0;i--) vec[i]->update();
        tree=vec[0];
    }

    void rotate(Node *x) {
        if(!x) return;
        Node *p=x->p, *b=0;
        p->prop(), x->prop();
        if(!p) return;
        if(x==p->l) p->l=b=x->r, x->r=p;
        else p->r=b=x->l, x->l=p;
        x->p=p->p, p->p=x;
        if(b) b->p=p;

        (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
        p->update(), x->update();
    }
    void splay(Node *x) {
        if(!x) return;
        while(x->p) {
            Node *p=x->p, *g=p->p;
            if(g) rotate((x==p->l) == (p==g->l) ? p : x);
            rotate(x);
        }
        x->prop();
    }

    void kth(int k) {
        Node *x=tree;
        if(!x || k>n) return;
        x->prop();
        while(1) {
            while(x->l && x->l->cnt > k) x=x->l, x->prop();
            if(x->l) k-=x->l->cnt;
            if(!k--) break;
            x=x->r;
            x->prop();
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
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    SplayTree<int> tree(v);

    cin >> q;
    for(int i=0;i<q;i++) {
        int a,l,r; cin >> a >> l >> r;
        if(a==1) tree.rev(l,r);
        else cout << tree.gather(l,r)->mx << '\n';
    }
    return 0;
}