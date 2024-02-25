#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Node {
    ll v;
    Node *l, *r;
    Node() { l=r=nullptr, v=0; }
};

Node *root[505050];
int N, M;

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

ll q5(Node *l, Node *r, int s, int e, int k) {
    if(s==e) return s;
    int diff=r->l->v-l->l->v, m=s+e>>1;
    if(k<=diff) return q5(l->l,r->l,s,m,k);
    else return q5(l->r,r->r,m+1,e,k-diff);
}

ll q4(Node *nl, Node *nr, int s, int e, int l, int r) {
    if(e<l || s>r) return 0;
    if(l<=s && e<=r) return nr->v-nl->v;
    int m=s+e>>1;
    return q4(nl->l,nr->l,s,m,l,r)+q4(nl->r,nr->r,m+1,e,l,r);
}

void q2(Node *l, Node *r, int s, int e, const char *b, string& res) {
    if(*b==0) return;
    int a=(*b-'0')^1, m=s+e>>1;
    if(a) {
        if(r->r->v-l->r->v) res+='1', q2(l->r,r->r,m+1,e,b+1,res);
        else res+='0', q2(l->l,r->l,s,m,b+1,res);
    } else {
        if(r->l->v-l->l->v) res+='0', q2(l->l,r->l,s,m,b+1,res);
        else res+='1', q2(l->r,r->r,m+1,e,b+1,res);
    }
}

const int S=0,E=(1<<19)-1;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M;
    root[0]=new Node();
    build(root[0], S, E);
    for(int i=1,op,x,l,r,k,sz=0;i<=M;i++) {
        cin >> op;
        if(op==1) {
            cin >> x;
            sz++;
            if(root[sz]) delete root[sz];
            root[sz]=new Node();
            add(root[sz-1],root[sz],S,E,x,1);
        } else if(op==2) {
            cin >> l >> r >> x;
            string res="";
            q2(root[l-1],root[r],S,E,bitset<19>(x).to_string().c_str(),res);
            cout << stoi(res,0,2) << "\n";
        } else if(op==3) {
            cin >> k;
            sz-=k;
        } else if(op==4) {
            cin >> l >> r >> x;
            cout << q4(root[l-1],root[r],S,E,1,x) << '\n';
        } else if(op==5) {
            cin >> l >> r >> k;
            cout << q5(root[l-1],root[r],S,E,k) << '\n';
        }
    }
    return 0;
}