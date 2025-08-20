#include <bits/stdc++.h>
using namespace std;

struct node{
    int size=0,row=0; node *col=nullptr,*u=this,*d=this,*l=this,*r=this;
};

static inline void cover(node* c){
    c->r->l=c->l; c->l->r=c->r;
    for(node* i=c->d;i!=c;i=i->d) for(node* j=i->r;j!=i;j=j->r) {
        j->d->u=j->u; j->u->d=j->d; j->col->size--;
    }
}
static inline void uncover(node* c){
    for(node* i=c->u;i!=c;i=i->u) for(node* j=i->l;j!=i;j=j->l) {
        j->col->size++; j->d->u=j; j->u->d=j;
    }
    c->r->l=c; c->l->r=c;
}

static bool search(node* head, vector<int>& ans){
    if(head->r==head) return true;
    node* c=nullptr; int mn=1e9;
    for(node* it=head->r; it!=head; it=it->r) {
        if(it->size<mn) {
            if(!it->size) return false; mn=it->size; c=it;
        }
    }
    cover(c);
    for(node* r=c->d; r!=c; r=r->d) {
        ans.push_back(r->row);
        for(node* j=r->r; j!=r; j=j->r) cover(j->col);
        if(search(head,ans)) return true;
        for(node* j=r->l; j!=r; j=j->l) uncover(j->col);
        ans.pop_back();
    }
    uncover(c); return false;
}

vector<int> dlx_solve(const vector<vector<int>>& A){
    if(A.empty()||A[0].empty()) return {};
    int m=A.size(), n=A[0].size();
    vector<node> col(n);
    node head;
    head.r=&col[0], head.l=&col[n-1];
    for(int i=0;i<n;i++) {
        col[i].u=col[i].d=&col[i];
        col[i].size=0;
        col[i].l=(i?&col[i-1]:&head), col[i].r=(i+1<n?&col[i+1]:&head);
    }
    deque<node> pool; pool.clear();
    auto add_node = [&](int r,int c) {
        pool.emplace_back(); node* x=&pool.back();
        x->row=r, x->col=&col[c];
        x->u=col[c].u, x->d=&col[c], col[c].u->d=x, col[c].u=x, col[c].size++;
        return x;
    };
    for(int i=0;i<m;i++) {
        node* last=nullptr;
        for(int j=0;j<n;j++) if(A[i][j]) {
            node* x=add_node(i,j);
            if(!last) x->l=x->r=x;
            else  x->l=last, x->r=last->r, last->r->l=x, last->r=x;
            last=x;
        }
    }
    vector<int> ans;
    search(&head,ans);
    return ans;
}

int B[9][9];

void sol(int tc) {
    vector<vector<int>> m, v;
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) {
        cin >> B[i][j];
        for(int k=0;k<9;k++) {
            if(B[i][j] && B[i][j]-1 != k) continue;
            vector<int> row(324);
            row[i*9+j]=row[81+i*9+k]=row[81*2+j*9+k]=row[81*3+((i/3*3)+j/3)*9+k]=1;
            m.push_back(row), v.push_back({i,j,k+1});
        }
    }
    for(auto r:dlx_solve(m)) B[v[r][0]][v[r][1]]=v[r][2];
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) cout << B[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}