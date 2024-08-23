#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct Node {
    Node *l, *r, *p;
    int sz;
    T v, s, a, d, sum;
    Node(T v=0) : v(v), sum(v) {l=r=p=nullptr, sz=1, s=-1, a=d=0;}
    ~Node() {for(auto i:{l,r}) if(i) delete i;}
};

template<typename T>
struct SplayTree {
    Node<T> *root;
    SplayTree(vector<T> v){
        v.insert(v.begin(), T(0));
        v.push_back(T(0));
        root = build(v, 0, (int)v.size()-1);
    }
    Node<T>* build(const vector<T> &v, int l, int r){
        if(l > r) return nullptr;
        int m = (l + r) / 2;
        auto x = new Node<T>(v[m]);
        x->l = build(v, l, m-1); if(x->l) x->l->p = x;
        x->r = build(v, m+1, r); if(x->r) x->r->p = x;
        update(x);
        return x;
    }
    void push(Node<T> *x) {
        if(x->s >= 0) {
            x->v = x->s, x->sum = x->v * x->sz;
            for(Node<T> *i:{x->l, x->r}) if(i) i->s=x->s, i->a=i->d=0;
        }
        if(x->d) {
            int sz = (x->l ? x->l->sz : 0) + 1;
            x->v += x->a + sz * x->d;
            x->sum += (2*x->a + (x->sz+1)*x->d) * x->sz / 2;

            for(Node<T> *i:{x->l, x->r}) if(i) {
                i->a+=x->a, i->d+=x->d;
                if(i==x->r) i->a+=sz*x->d;
            }
        }
        x->a=x->d=0, x->s=-1;
    }

    void update(Node<T> *x) {
        push(x), x->sz=1, x->sum=x->v;
        for(Node<T> *i:{x->l, x->r}) if(i) push(i), x->sz+=i->sz, x->sum+=i->sum;
    }

    void rotate(Node<T> *x) {
        Node<T> *p=x->p, *b=0;
        if(!p) return;
        if(x==p->l) p->l=b=x->r, x->r=p;
        else p->r=b=x->l, x->l=p;
        x->p=p->p, p->p=x;
        if(b) b->p=p;

        (x->p ? p == x->p->l ? x->p->l : x->p->r : root) = x;
        update(p), update(x);
    }

    void splay(Node<T> *x) {
        while(x->p) {
            Node<T> *p=x->p, *g=p->p;
            if(g) rotate((x==p->l) == (p==g->l) ? p : x);
            rotate(x);
        }
    }

    Node<T>* kth(int k) {
        Node<T> *x=root;
        update(x);
        while(1) {
            while(x->l && x->l->sz > k) x=x->l, update(x);
            if(x->l) k-=x->l->sz;
            if(!k--) break;
            x=x->r;
            update(x);
        }
        splay(x);
        return x;
    }

    Node<T>* gather(int l, int r) {
        kth(l-1);
        Node<T> *x = root;
        root=x->r, root->p=0;
        kth(r-l+1);
        x->r=root, root->p=x;
        root=x;
        return root->r->l;
    }
    
    void range_set(int l, int r, int k) {
        Node<T> *x=gather(l,r);
        x->s=k, x->a=x->d=0;
        while(x) update(x), x=x->p;
    }

    void range_add(int l, int r, int k) {
        Node<T> *x = gather(l,r);
        x->a=0, x->d=k;
        while(x) update(x), x=x->p;
    }

    void insert_after(int i, int v) {
        kth(i);
        auto x = new Node<T>(v), r = root->r;
        x->r = r; r->p = x; 
        root->r = x; x->p = root;
        update(x), update(root), splay(x);
    }

    ll sum(int l, int r) {return gather(l,r)->sum;}

    vector<T> inorder() {
        vector<T> res;
        int pv=0, n=root->sz;
        function<void(Node<T>*)> dfs = [&](Node<T>* x) {
            prop(x);
            if(x->l) dfs(x->l);
            if(1<++pv && pv<n) res.push_back(x->v);
            if(x->r) dfs(x->r);
        };

        dfs(root);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    SplayTree vec(v);

    for(int i=0,op,a,b,x;i<q;i++) {
        cin >> op >> a >> b;
        if(op==1) cin >> x, vec.range_set(a,b,x);
        else if(op==2) cin >> x, vec.range_add(a,b,x);
        else if(op==3) vec.insert_after(a-1,b);
        else cout << vec.sum(a,b) << '\n';
    }
    return 0;
}