#include <bits/stdc++.h>
using namespace std;
using T = long long;
constexpr T INF = 1212121212;

// https://github.com/justiceHui/icpc-teamnote/blob/master/code/DataStructure/Splay-LCT.cpp
struct Node{
    Node *l, *r, *p; bool flip; int sz; T now, mn;
    Node(){ l = r = p = nullptr; sz = 1; flip = false; now = mn = INF; }
    bool IsLeft() const { return p && this == p->l; }
    bool IsRoot() const { return !p || (this != p->l && this != p->r); }
    friend int GetSize(const Node *x){ return x ? x->sz : 0; }
    friend T GetSum(const Node *x){ return x ? x->mn : INF; }
    void Rotate(){
        p->Push(); Push();
        if(IsLeft()) r && (r->p = p), p->l = r, r = p;
        else l && (l->p = p), p->r = l, l = p;
        if(!p->IsRoot()) (p->IsLeft() ? p->p->l : p->p->r) = this;
        auto t = p; p = t->p; t->p = this; t->Update(); Update();
    }
    void Update(){
        sz = 1 + GetSize(l) + GetSize(r); mn = min({now, GetSum(l), GetSum(r)});
    }
    void Update(const T &val){ now = val; Update(); }
    void Push(){
        if(flip) swap(l, r);
        for(auto c : {l, r}) if(c) c->flip ^= flip;
        flip = false;
    }
};

Node* Splay(Node *x){
    for(; !x->IsRoot(); x->Rotate()){
        if(!x->p->IsRoot()) x->p->p->Push();
        x->p->Push(); x->Push();
        if(!x->p->IsRoot()) (x->IsLeft() ^ x->p->IsLeft() ? x : x->p)->Rotate();
    }
    x->Push(); return x;
}
void Access(Node *x){
    Splay(x); x->r = nullptr; x->Update();
    for(auto y=x; x->p; Splay(x)) y = x->p, Splay(y), y->r = x, y->Update();
}
int GetDepth(Node *x){ Access(x); x->Push(); return GetSize(x->l); }
Node* GetRoot(Node *x){
    Access(x); for(x->Push(); x->l; x->Push()) x = x->l; return Splay(x);
}
Node* GetPar(Node *x){
    Access(x); x->Push(); if(!x->l) return nullptr;
    x = x->l; for(x->Push(); x->r; x->Push()) x = x->r;
    return Splay(x);
}
void Link(Node *p, Node *c){ Access(c); Access(p); c->l = p; p->p = c; c->Update(); }
void Cut(Node *c){ Access(c); c->l->p = nullptr; c->l = nullptr; c->Update(); }
Node* GetLCA(Node *x, Node *y){
    Access(x); Access(y); Splay(x); return x->p ? x->p : x;
}

Node N[1010101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) N[i].now=i;

    for(int i=0,op,u,v;i<m;i++) {
        cin >> op;
        if(op==1) cin >> u >> v, Link(N+v, N+u);
        else if(op==2) cin >> v, Cut(N+v);
        else {
            cin >> u >> v;
            if(GetRoot(N+u) == GetRoot(N+v)) cout << GetLCA(N+u,N+v)->now << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}