#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename T>
struct SplayTree {
    struct Node {
        Node *l, *r, *p;
        int cnt, inv;
        T val;
        Node(T val) : l(0), r(0), p(0), val(val), cnt(0), inv(0) {}
        ~Node(){
            if(l) delete l;
            if(r) delete r;
        }
    } *tree;
    Node *vec[303030];
    int n;

    SplayTree(vector<T> v) : n(v.size()) {
        vec[0]=new Node(0), vec[n+1]=new Node(0);
        for(int i=1;i<=n;i++) vec[i]=new Node(v[i-1]);
        for(int i=1;i<=n;i++) vec[i]->p=vec[i-1], vec[i]->r=vec[i+1];
        vec[0]->r=vec[1], vec[n+1]->p=vec[n];
        for(int i=n+1;i>=0;i--) update(vec[i]);
        tree=vec[0];

        sort(vec+1, vec+n+1, [](Node *a, Node *b) {
            return a->val < b->val;
        });
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
        x->val;
        if(x->l) x->cnt+=x->l->cnt;
        if(x->r) x->cnt+=x->r->cnt;
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
    void splay(Node *x) {
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
    int idx(int i) {
        splay(vec[i]);
        return tree->l->cnt;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while (cin >> n && n) {
        vector<pair<int,int>> v;
        for(int i=0,a;i<n;i++) cin >> a, v.push_back({a,i});
        sort(v.begin(),v.end());
        vector<int> vv(n);
        for(int i=0;i<n;i++) vv[v[i].second]=i+1;

        SplayTree<int> s(vv);
        for(int i=1,j;i<=n;i++) {
            j=s.idx(i);
            cout << j << ' ';
            s.rev(i,j);
        }
        cout << '\n';
    }
    return 0;
}