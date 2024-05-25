#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *l, *r, *p;
    int key;
    Node() : l(0), r(0), p(0), key(0) { }
    Node(int key) : l(0), r(0), p(0), key(key) { }
} *tree;

void rotate(Node *x) {
    Node *p=x->p, *b=nullptr;
    if(!p) return;
    if(x==p->l) p->l=b=x->r, x->r=p;
    else p->r=b=x->l, x->l=p;
    x->p=p->p, p->p=x;
    if(b) b->p=p;

    if(!x->p) tree=x;
    else p==x->p->l ? x->p->l=x : x->p->r=x;
}
void splay(Node *x) {
    while(x->p) {
        Node *p=x->p, *g=p->p;
        if(g) (x==p->l) == (p==g->l) ? rotate(p) : rotate(x);
        rotate(x);
    }
}

void insert(int key) {
    Node *x=new Node(key), *p=tree;
    if(!tree) {tree=x; return;}
    while(1) {
        if(key == p->key) return;
        if(key < p->key) {
            if(!p->l) {p->l=x, x->p=p; break;}
            p=p->l;
        } else {
            if(!p->r) {p->r=x, x->p=p; break;}
            p=p->r;
        }
    }
    splay(x);
}

bool find(int key) {
    if(!tree) return 0;
    Node *p=tree;
    while(p) {
        if(key==p->key) return 1;
        if(key < p->key) {
            if(!p->l) break;
            p=p->l;
        } else {
            if(!p->r) break;
            p=p->r;
        }
    }
    splay(p);
    return key==p->key;
}

void del(int key) {
    if(!find(key)) return;
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c=0; cin >> a >> b;
    for(int i=0,x;i<a;i++) cin >> x, insert(x);
    for(int i=0,x;i<b;i++) cin >> x, c+=find(x);
    cout << a+b-c-c;
    return 0;
}