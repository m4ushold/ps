#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Node {
    ll v;
    Node *l, *r;
    Node() { l=r=nullptr, v=0; }
};

const ll sz=1<<18;
Node *root[sz];
ll N, M, A[sz], B[sz], S[sz];

ll f(ll a, ll b) { return a+b; }

void build(Node* node, ll s, ll e) {
    if(s==e) {node->v=0; return;}
    ll m=s+e>>1;
    node->l=new Node(), node->r= new Node();
    build(node->l,s,m), build(node->r,m+1,e);
    node->v=f(node->l->v, node->r->v);
}

void add(Node *prev, Node *now, ll s, ll e, ll x, ll v) {
    if(s==e) {now->v=prev->v + v; return;}
    ll m=s+e>>1;
    if(x<=m) {
        now->l=new Node(), now->r=prev->r;
        add(prev->l, now->l,s,m,x,v);
    } else {
        now->r=new Node(), now->l=prev->l;
        add(prev->r, now->r,m+1,e,x,v);
    }
    now->v=f(now->l->v, now->r->v);
}

ll query(Node *l, Node *r, ll s, ll e, ll k) {
    if(s==e) return s;
    ll diff=r->l->v-l->l->v, m=s+e>>1;
    if(k<=diff) return query(l->l,r->l,s,m,k);
    else return query(l->r,r->r,m+1,e,k-diff);
}

void init() {
    root[0]=new Node();
    build(root[0],1,N);

    map<ll,ll> m;
    sort(S+1, S+N+1);
    for(ll i=1;i<=N;i++) m[S[i]]=i;
    for(ll i=1;i<=N;i++) root[i]=new Node(), add(root[i-1],root[i],1,N,m[A[i]],1);
}

ll qry(ll r, ll k) { // [1,r] kth num
    return S[query(root[0],root[r],1,N,k)];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    N++;
    for(ll i=2;i<=N;i++) cin >> A[i], A[i]+=A[i-1], B[i]=1, S[i]=A[i];
    init();

    priority_queue<pair<ll,ll>> pq;
    for(ll i=2;i<=N;i++) {
        pq.push({A[i]-qry(i-1,B[i]), i});
        B[i]++;
    }

    while(M--) {
        auto [a,i] = pq.top(); pq.pop();
        cout << a << ' ';
        if(B[i] < i) {
            pq.push({A[i]-qry(i-1,B[i]), i});
            B[i]++;
        }
    }
    return 0;
}