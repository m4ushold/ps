#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename T>
struct SplayTree {
    struct Node {
        Node *l, *r, *p;
        int cnt;
        T val;
        bool inv;
        Node(int val=0) : l(0), r(0), p(0), val(val), cnt(0), inv(0) {}
        ~Node(){
            if(l) delete l;
            if(r) delete r;
        }
    } *tree;

    SplayTree(vector<T> v) {
        int n=v.size();
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
    SplayTree<char> splay(vector<char>(s.begin(),s.end()));
    int t; cin >> t;
    while(t--) {
        int s,e; cin >> s >> e;
        splay.reverse(s,e);
    }
    for(int i=1;i<=s.size();i++) splay.kth(i), cout << splay.tree->val;
    return 0;
}