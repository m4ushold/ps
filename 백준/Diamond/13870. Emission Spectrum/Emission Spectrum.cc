#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Node {
    ll v;
    Node *l, *r;
    Node() { l=r=nullptr, v=0; }
};

Node *root[101010];
int N, Q, A[101010];

ll f(ll a, ll b) { return a+b; }

void build(Node* node, int s=1, int e=N) {
    if(s==e) {node->v=0; return;}
    int m=s+e>>1;
    node->l=new Node(), node->r= new Node();
    build(node->l,s,m), build(node->r,m+1,e);
    node->v=f(node->l->v, node->r->v);
}

void add(Node *prev, Node *now, int x, int v, int s=1, int e=N) {
    if(s==e) {now->v=prev->v+v; return;}
    int m=s+e>>1;
    if(x<=m) {
        now->l=new Node(), now->r=prev->r;
        add(prev->l, now->l,x,v,s,m);
    } else {
        now->r=new Node(), now->l=prev->l;
        add(prev->r, now->r,x,v,m+1,e);
    }
    now->v=f(now->l->v, now->r->v);
}

int query(Node *l, Node *r, int k, int s=1, int e=N) {
    if(s==e) return s;
    int diff=r->l->v - l->l->v, m=s+e>>1;
    if(k<=diff) return query(l->l,r->l,k,s,m);
    else return query(l->r,r->r,k-diff,m+1,e);
}

void update(Node *prev, Node *now, int x, int v, int s=1, int e=N) {
    if(s==e) {now->v=prev->v+v; return;}
    int m=s+e>>1;
    if(x<=m) {
        now->r=prev->r;
        update(prev->l, now->l,x,v,s,m);
    } else {
        now->l=prev->l;
        update(prev->r, now->r,x,v,m+1,e);
    }
    now->v=f(now->l->v, now->r->v);
}

void swap(int w) {
    swap(A[w],A[w+1]);
    root[w]=new Node();
    add(root[w-1],root[w],A[w],1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    
    vector<int> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    root[0]=new Node();
    build(root[0]);
    for(int i=1;i<=N;i++) {
        root[i]=new Node();
        add(root[i-1],root[i],A[i],1);
    }
    
    for(int i=0,s,e,k,w;i<Q;i++) {
        char c; cin >> c;
        if(c=='Q') cin >> s >> e >> k, cout << v[query(root[s-1],root[e],k)-1] << '\n';
        else cin >> w, swap(w);
    }
    return 0;
}