#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Node {
    ll v;
    Node *l, *r;
    Node() { l=r=nullptr, v=0; }
};

Node *root[101010], *B[101010];
int N, M, A[101010], R[101010], P[101010];

ll f(ll a, ll b) { return a+b; }

void build(Node* node, int s, int e) {
    if(s==e) {node->v=0; return;}
    int m=s+e>>1;
    node->l=new Node(), node->r= new Node();
    build(node->l,s,m), build(node->r,m+1,e);
    node->v=f(node->l->v, node->r->v);
}

void add(Node *prev, Node *now, int s, int e, int x, int v) {
    if(s==e) {now->v=prev->v+v; return;}
    int m=s+e>>1;
    if(x<=m) {
        now->l=new Node(), now->r=prev->r;
        add(prev->l, now->l,s,m,x,v);
    } else {
        now->r=new Node(), now->l=prev->l;
        add(prev->r, now->r,m+1,e,x,v);
    }
    now->v=f(now->l->v, now->r->v);
}

// find kth element in range[l+1,r]
ll query(Node *l, int s, int e, int k) {
    if(s==e) return s;
    int diff=l->l->v, m=s+e>>1;
    if(k<=diff) return query(l->l,s,m,k);
    else return query(l->r,m+1,e,k-diff);
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=N;i;i--) R[i]=P[A[i]], P[A[i]]=i;

    root[N+2] = new Node;
    build(root[N+2], 1, N+1);
    root[N+1] = new Node;
    add(root[N+2],root[N+1],1,N+1,N+1,1e5);
    // build pst
    for(int i=N;i;i--) {
        Node *tmp=root[i+1];
        root[i] = new Node;
        if(R[i]) {
            tmp = new Node;
            add(root[i+1],tmp,1,N+1,R[i],-1);
        }
        add(tmp,root[i],1,N+1,i,1);
    }

    int p=0,q; cin >> q;
    for(int i=0;i<q;i++) {
        int x,y; cin >> x >> y;
        int l = (x+p)%N+1, k = (y+p)%M+1;
        int r = query(root[l], 1, N+1, k);
        if(r == N+1) r=0;
        cout << r << '\n';
        p=r;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}