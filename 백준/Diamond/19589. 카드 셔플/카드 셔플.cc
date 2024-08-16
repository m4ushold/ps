#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SplayTree {
    struct Node {
        Node *l, *r, *p;
        int cnt, mn, mx, h;
        ll sum;
        int val;
        bool inv;
        Node(int val) : l(0), r(0), p(0), val(val), cnt(0), inv(0),mn(0),mx(0),sum(0),h(1) {}
        ~Node(){
            if(l) delete l;
            if(r) delete r;
        }
    } *tree;
    vector<int> in;
    int n;

    SplayTree(vector<int> v) : n(v.size()) {
        Node *x=new Node(0), *y;
        v.push_back(0);
        for(int i=0;i<n+1;i++) {
            y = new Node(v[i]);
            x->r=y, y->p=x, x=y;
        }
        while(x->p) update(x), x=x->p;
        update(x);
        tree=x;
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

    void up(int l, int r) {
        rev(l,r), rev(1,l-1), rev(1,r);
    }
    
    void down(int l, int r) {
        rev(l,r), rev(r+1,n), rev(l,n);
    }

    vector<int> riffleShuffle(const vector<int>& deck) {
        int n=deck.size(), j=0, k=n/2;
        vector<int> ret(n);
        for(int i=0;i<n;i++) {
            if(i&1) ret[i]=deck[k++];
            else ret[i]=deck[j++];
        }
        return ret;
    }
    
    void shuffle(int l, int r) {
        Node *x=gather(l,r);
        vector<int> v=inorder(x);
        v=riffleShuffle(v);

        int idx=0;
        function<void(Node*)> dfs = [&](Node* x) {
            prop(x);
            if (x->l) dfs(x->l);
            if(x->val) x->val = v[idx++];
            if (x->r) dfs(x->r);
        };
        dfs(x);
    }

    vector<int> inorder() {
        in.clear();
        dfs(tree);
        return in;
    }
    vector<int> inorder(Node *x) {
        in.clear();
        dfs(x);
        return in;
    }

    void dfs(Node *x) {
        prop(x);
        if(x->l) dfs(x->l);
        if(x->val) in.push_back(x->val);
        if(x->r) dfs(x->r);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);

    SplayTree tree(v);
    for(int i=0,op,x,y;i<q;i++) {
        cin >> op >> x >> y;
        if(op==1) tree.up(x,y);
        else if(op==2) tree.down(x,y);
        else tree.shuffle(x,y);
    }

    for(auto i:tree.inorder()) cout << i << ' ';
    cout << "\n";

    return 0;
}