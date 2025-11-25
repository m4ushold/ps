#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;


struct Node {
    ll v;
    Node *l, *r;
    Node() { l=r=nullptr, v=0; }
    ~Node() { 
        if(l!=nullptr) delete l;
        if(r!=nullptr) delete r;
    }
};

constexpr int sz = 1<<17;
ll N, Q, A[sz], B[sz], AS[sz], BS[sz];

Node *sum[sz], *cnt[sz];
ll op(ll a, ll b) { return a+b; }
void build(Node* node, int s=1, int e=N+1) {
    if(s==e) {node->v=0; return;}
    int m=s+e>>1;
    node->l=new Node(), node->r= new Node();
    build(node->l,s,m), build(node->r,m+1,e);
    node->v=op(node->l->v, node->r->v);
}

void add(Node *prev, Node *now, int x, int v, int s=1, int e=N+1) {
    if(s==e) {now->v=prev->v+v; return;}
    int m=s+e>>1;
    if(x<=m) {
        now->l=new Node(), now->r=prev->r;
        add(prev->l, now->l,x,v,s,m);
    } else {
        now->r=new Node(), now->l=prev->l;
        add(prev->r, now->r,x,v,m+1,e);
    }
    now->v=op(now->l->v, now->r->v);
}

ll query(Node *node, int l, int r, int s=1, int e=N+1) {
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return node->v;
    int m=s+e>>1;
    return op(query(node->l,l,r,s,m),query(node->r,l,r,m+1,e));
}

int kth(Node *node, int k, int s=1, int e=N+1) {
    if(s==e) return s;
    int m=s+e>>1;
    if(k<=node->l->v) return kth(node->l, k, s, m);
    else return kth(node->r, k-node->l->v, m+1, e);
}

bool chk(int k, ll x, ll y) {
    x-=AS[k];
    if(x<0) return 0;
    if(k-x<=0) return 1;
    int j = kth(cnt[k], k-x+1);
    return BS[k] - query(sum[k], j, N+1) <= y;
}

ll qry(ll x, ll y) {
    int l=0, r=N;
    while(l<r) {
        int m = l+r+1>>1;
        if(chk(m,x,y)) l=m;
        else r=m-1;
    }
    return l;
}

void sol(int tc) {
    cin >> N;
    vector<array<int,3>> v(N);
    for(int i=0;i<N;i++) {
        auto &[a,b,j] = v[i];
        cin >> a >> b;
    }
    sort(all(v), [](array<int,3> a, array<int,3> b){
        return a[1] < b[1];
    });
    for(int i=0;i<N;i++) v[i][2]=i+1;
    sort(all(v));
    sum[0] = new Node(), cnt[0] = new Node();
    build(sum[0]), build(cnt[0]);
    for(int i=1;i<=N;i++) {
        auto [a,b,j] = v[i-1];
        A[i]=a, B[i]=b;
        AS[i] = AS[i-1] + a, BS[i] = BS[i-1] + b;

        sum[i] = new Node();
        add(sum[i-1], sum[i], j, b);

        cnt[i] = new Node();
        add(cnt[i-1], cnt[i], j, 1);
    }

    cin >> Q;
    for(int i=1;i<=Q;i++) {
        ll x,y; cin >> x >> y;
        cout << qry(x,y) << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}