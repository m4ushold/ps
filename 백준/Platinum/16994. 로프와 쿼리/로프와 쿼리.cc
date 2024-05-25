#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SplayTree {
    struct Node {
        Node *l, *r, *p;
        int cnt, val;
        bool inv;
        Node(int val=0) : l(0), r(0), p(0), val(val), cnt(0), inv(0) {}
        ~Node(){
            if(l) delete l;
            if(r) delete r;
        }
    } *tree;

    SplayTree(int n, string v) {
        Node *x=new Node();
        tree=x;
        x->cnt=n+2;
        for(int i=0;i<=n;i++) {
            x->r=new Node(i<n ? v[i] : 0), x->r->p=x;
            x=x->r, x->cnt=n-i+1;
        }
    }
    
    void prop(Node *x) {
        if (!x->inv) return;
        swap(x->l, x->r);
        x->inv=0;
        if(x->l) x->l->inv=!x->l->inv;
        if(x->r) x->r->inv=!x->r->inv;
    }
    
    void update(Node *x) {
        x->cnt = 1;
        if(x->l) x->cnt += x->l->cnt;
        if(x->r) x->cnt += x->r->cnt;
    }

    void rotate(Node *x) {
        Node *p=x->p, *b=0;
        if(!p) return;
        if(x==p->l) p->l=b=x->r, x->r=p;
        else p->r=b=x->l, x->l=p;
        x->p=p->p, p->p=x;
        if(b) b->p=p;

        (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
        update(p), update(x);
    }
    void splay(Node *x) {
        while(x->p) {
            Node *p=x->p, *g=p->p;
            if(g) rotate((x==p->l) == (p==g->l) ? p : x);
            rotate(x);
        }
    }

    void insert(ll val=0) {
        Node *x=new Node(val), *p=tree;
        if(!tree) {tree=x; return;}
        while(1) {
            if(val == p->val) return;
            if(val < p->val) {
                if(!p->l) {p->l=x, x->p=p; break;}
                p=p->l;
            } else {
                if(!p->r) {p->r=x, x->p=p; break;}
                p=p->r;
            }
        }
        splay(x);
    }

    bool find(int val) {
        if(!tree) return 0;
        Node *p=tree;
        while(1) {
            if(val==p->val) return 1;
            if(val < p->val) {
                if(!p->l) break;
                p=p->l;
            } else {
                if(!p->r) break;
                p=p->r;
            }
        }
        splay(p);
        return val==p->val;
    }

    void del(int val) {
        if(!find(val)) return;
        Node *p=tree;
        if(p->l && p->r) {
            tree=p->l, tree->p=0;

            Node *x = tree;
            while(x->r) x=x->r;
            x->r=p->r, p->r->p=x;
            delete p;
            return;
        } else if(p->l) {
            tree=p->l, tree->p=0;
            delete p;
            return;
        } else if(p->r) {
            tree=p->r, tree->p=0;
            delete p;
            return;
        }
        delete p;
        tree=0;
    }

    void kth(int k) {
        if(!tree) return;
        Node *x=tree;
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

    void reverse(int l, int r) {
        if(l>r) return;
        Node *x = gather(l,r);
        x->inv=!x->inv;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n=s.size();
    SplayTree tree(n,s);

    int q; cin >> q;
    for(int i=0,a,x,y;i<q;i++) {
        cin >> a >> x;
        if(a==1) cin >> y, ++x, ++y, tree.reverse(1,y), tree.reverse(1,y-x+1), tree.reverse(y-x+2,y);
        else if(a==2) cin >> y, ++x, ++y, tree.reverse(x,n), tree.reverse(x,n-(y-x+1)), tree.reverse(n-y+x,n);
        else tree.kth(x+1), cout << (char)tree.tree->val << '\n';
    }
    return 0;
}