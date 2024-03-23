#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Node {
    ll v;
    Node *l, *r;
    Node() { l=r=nullptr, v=0; }
    ~Node() { 
        if(l!=nullptr) delete l;
        if(r!=nullptr) delete r;
    }
};

Node *root[101010];
int N, M, A[101010], B[101010], C[101010], D[101010], P[22][101010];
vector<int> G[101010];

ll f(ll a, ll b) { return a+b; }

void build(Node* node, int s=1, int e=N) {
    if(s==e) {node->v=0; return;}
    int m=s+e>>1;
    node->l=new Node(), node->r= new Node();
    build(node->l,s,m), build(node->r,m+1,e);
    node->v=f(node->l->v, node->r->v);
}

void add(Node *prev, Node *now, int x, int v, int s=1, int e=N) {
    if(s==e) {now->v+=v; return;}
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

void dfs(int v, int p=0) { 
    root[v]=new Node();
    add(root[p],root[v],C[v],1);
    for(auto i:G[v]) if(i!=p) {
        D[i]=D[v]+1, P[0][i]=v, dfs(i,v);
    }
}

int lca(int u, int v) {
    if(D[u]<D[v]) swap(u,v);
    int diff=D[u]-D[v];
    for(int i=0;diff;i++,diff>>=1) if(diff&1) u=P[i][u];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    return P[0][u];
}

int query(Node *u, Node *v, Node *lca, Node* lcap, int k, int s=1, int e=N) {
    if(s==e) return s;
    int diff=u->l->v + v->l->v - lca->l->v - lcap->l->v, m=s+e>>1;
    if(k<=diff) return query(u->l,v->l,lca->l,lcap->l,k,s,m);
    else return query(u->r,v->r,lca->r,lcap->r,k-diff,m+1,e);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i], B[i]=A[i];
    sort(B+1,B+N+1);
    for(int i=1;i<=N;i++) C[i]=lower_bound(B+1,B+N+1,A[i])-B;

    for(int i=1,a,b;i<N;i++) cin >> a >> b, G[a].push_back(b), G[b].push_back(a);
    root[0]=new Node();
    build(root[0]);
    dfs(1);
    for(int i=1;i<22;i++) for(int j=1;j<=N;j++) P[i][j]=P[i-1][P[i-1][j]];
    for(int i=0,x,y,k;i<M;i++) {
        cin >> x >> y >> k;
        int l=lca(x,y);
        cout << B[query(root[x],root[y],root[l],root[P[0][l]],k)] << '\n';
    }

    return 0;
}