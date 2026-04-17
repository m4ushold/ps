#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// https://github.com/justiceHui/icpc-teamnote/blob/master/code/DataStructure/Splay-LCT.cpp
struct Node {
  Node *l, *r, *p;
  bool flip;
  int sz;
  ll now, mn;
  Node() {
    l = r = p = nullptr;
    sz = 1;
    flip = false;
  }
  bool IsLeft() const { return p && this == p->l; }
  bool IsRoot() const { return !p || (this != p->l && this != p->r); }
  friend int GetSize(const Node *x) { return x ? x->sz : 0; }
  friend ll GetSum(const Node *x) { return x ? x->mn : 0; }
  void Rotate() {
    p->Push();
    Push();
    if (IsLeft())
      r && (r->p = p), p->l = r, r = p;
    else
      l && (l->p = p), p->r = l, l = p;
    if (!p->IsRoot())
      (p->IsLeft() ? p->p->l : p->p->r) = this;
    auto t = p;
    p = t->p;
    t->p = this;
    t->Update();
    Update();
  }
  void Update() {
    sz = 1 + GetSize(l) + GetSize(r);
    mn = min({now, GetSum(l), GetSum(r)});
  }
  void Update(const ll &val) {
    now = val;
    Update();
  }
  void Push() {
    if (flip)
      swap(l, r);
    for (auto c : {l, r})
      if (c)
        c->flip ^= flip;
    flip = false;
  }
};

Node *Splay(Node *x) {
  for (; !x->IsRoot(); x->Rotate()) {
    if (!x->p->IsRoot())
      x->p->p->Push();
    x->p->Push();
    x->Push();
    if (!x->p->IsRoot())
      (x->IsLeft() ^ x->p->IsLeft() ? x : x->p)->Rotate();
  }
  x->Push();
  return x;
}
void Access(Node *x) {
  Splay(x);
  x->r = nullptr;
  x->Update();
  for (auto y = x; x->p; Splay(x))
    y = x->p, Splay(y), y->r = x, y->Update();
}
int GetDepth(Node *x) {
  Access(x);
  x->Push();
  return GetSize(x->l);
}
Node *GetRoot(Node *x) {
  Access(x);
  for (x->Push(); x->l; x->Push())
    x = x->l;
  return Splay(x);
}
Node *GetPar(Node *x) {
  Access(x);
  x->Push();
  if (!x->l)
    return nullptr;
  x = x->l;
  for (x->Push(); x->r; x->Push())
    x = x->r;
  return Splay(x);
}
void Link(Node *p, Node *c) {
  Access(c);
  Splay(c);
  c->p = p;
  c->Update();
}
void Cut(Node *c) {
  Access(c);
  c->l->p = nullptr;
  c->l = nullptr;
  c->Update();
}
Node *GetLCA(Node *x, Node *y) {
  Access(x);
  Access(y);
  Splay(x);
  return x->p ? x->p : x;
}

Node N[101010];
vector<int> G[101010];
int P[101010], A[101010], B[202020], F[202020];

void dfs(int v = 1, int p = -1) {
  for (int i : G[v])
    if (i != p)
      dfs(i, v), P[i] = v;
}

void sol(int tc) {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pll> edge(n - 1);
  for (auto &[u, v] : edge)
    cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
  for (int i = 1; i <= n; i++)
    A[i] = 1;

  for (int i = 0, d; i < m; i++) {
    cin >> d;
    auto [u, v] = edge[d - 1];
    int c = P[u] == v ? u : v, p = c == u ? v : u;
    if (!F[d]) {
      int r = GetRoot(N + p) - N;
      A[r] += A[c] - B[d];
      Link(N + p, N + c);
      F[d] = 1;
    } else {
      int r = GetRoot(N + c) - N;
      Cut(N + c);
      A[c] = A[r];
      B[d] = A[r];
      F[d] = 0;
    }
  }

  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cout << A[GetRoot(N + x) - N] << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}