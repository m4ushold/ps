#include <bits/stdc++.h>
using namespace std;

unsigned C[11][11];

template<typename T>
struct node{
    node *l, *r, *p; int sz;
    T v, ans[11];
    node() : node(T(0)) {}
    node(T v) : l(nullptr), r(nullptr), p(nullptr), sz(1), v(v) {
        for(int i=0;i<11;i++) ans[i]=v;
    }
    bool is_left() const { return this == p->l; }
    bool is_root() const { return p == nullptr; }
    void update(){
        sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
        // update ans
        unsigned pw[11]={1};
        for(int i=1;i<11;i++) pw[i]=pw[i-1]*(l ? l->sz+1 : 1);
        for(int i=0;i<11;i++) {
            ans[i] = v * pw[i];
            if(l) ans[i]+=l->ans[i];
            if(r) for(int j=0;j<=i;j++) ans[i] += r->ans[j] * pw[i-j] * C[i][j];
        }
    }
    void push(){ /* use if lazy propagation */ }
    void rotate(){
        p->push(); push();
        if(is_left()) r && (r->p = p), p->l = r, r = p;
        else l && (l->p = p), p->r = l, l = p;
        if(p->p) (p->is_left()? p->p->l : p->p->r) = this;
        auto *t = p; p = t->p; t->p = this;
        t->update(); update();
    }
};

template<typename T>
struct splay_tree{
    node<T> *root;
    splay_tree() : splay_tree(vector<T>()) {}
    splay_tree(vector<T> v){
        root = new node<T>();
        v.insert(v.begin(), T(0));
        v.push_back(T(0));
        root = build(v, 0, (int)v.size()-1);
    }
    node<T>* build(const vector<T> &v, int l, int r){
        if(l > r) return nullptr;
        int m = (l + r) / 2;
        auto x = new node<T>(v[m]);
        x->l = build(v, l, m-1); if(x->l) x->l->p = x;
        x->r = build(v, m+1, r); if(x->r) x->r->p = x;
        x->update();
        return x;
    }
    node<T>* splay(node<T> *x, node<T> *g=nullptr){
        for(g || (root = x); x->p != g; x->rotate()){
            if(!x->p->is_root()) x->p->p->push();
            x->p->push(); x->push();
            if(x->p->p != g) (x->is_left() != x->p->is_left() ? x : x->p)->rotate();
        }
        x->push(); return x;
    }
    node<T>* insert_next_of_root(T v){
        auto x = new node<T>(v), r = root->r;
        x->r = r; r->p = x; x->update();
        root->r = x; x->p = root; root->update();
        return splay(x);
    }
    node<T>* insert_after(node<T> *prv, T v){
        splay(prv);
        return insert_next_of_root(v);
    }
    int order_of_node(node<T> *x){
        splay(x); return x->l->sz;
    }
    node<T>* kth(int k){
        for(auto x=root; x; x=x->r){
            for(; x->push(), x->l && x->l->sz > k; x=x->l);
            if(x->l) k -= x->l->sz;
            if(!k--) return splay(x);
        }
        return nullptr;
    }
    node<T>* gather_range(int s, int e){
        auto t = kth(e+1);
        return splay(t, kth(s-1))->l;
    }
    void erase(int s) {
        erase_range(s,s);
    }
    void erase_range(int s, int e){
        auto x = gather_range(s, e), p = x->p;
        p->l = nullptr; p->update(); p->p->update();
        delete x;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=10;i++) {
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    int n; cin >> n;
    vector<unsigned> v(n);
    for(auto &i:v) cin >> i;
    splay_tree<unsigned> tree(v);
    int m; cin >> m;
    for(unsigned i=0,q,p,l,r,v,k;i<m;i++) {
        cin >> q;
        if(q==1) {
            cin >> p >> v;
            tree.insert_after(tree.kth(p), v);
        } else if(q==2) {
            cin >> p;
            tree.erase(p+1);
        } else if(q==3) {
            cin >> p >> v;
            auto node = tree.kth(p+1);
            if(node) node->v = v, node->update();
        } else {
            cin >> l >> r >> k;
            cout << tree.gather_range(l+1,r+1)->ans[k] << '\n';
        }
    }
    return 0;
}