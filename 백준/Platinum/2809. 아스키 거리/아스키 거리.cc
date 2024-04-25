#include <bits/stdc++.h>
using namespace std;

int id_cnt, L[5050], A[303030];

struct Trie {
    const static int sz=26;
    map<char,Trie*> nxt;
    Trie *fail;
    int id;
    Trie() : id(-1), fail(0) {}
    ~Trie() {
        for(auto [c,p]:nxt) if(p) delete p;
        nxt.clear();
    }
    int insert(const char *s) {
        if(*s==0) return id==-1 ? id=++id_cnt : id;
        if(!nxt[*s]) nxt[*s]=new Trie();
        return nxt[*s]->insert(s+1);
    }
} *root;

void ahoy() {
    queue<Trie*> q;
    root->fail=root, q.push(root);
    while(!q.empty()) {
        auto v=q.front(); q.pop();
        for(auto &[c,nxt]:v->nxt) {
            Trie *u=nxt;
            if(!u) continue;
            if(v==root) u->fail=root;
            else {
                Trie *t=v->fail;
                while(t!=root && !t->nxt[c]) t=t->fail;
                if(t->nxt[c]) t=t->nxt[c];
                u->fail=t;
            }
            if(u->id==-1) u->id=u->fail->id;
            q.push(u);
        }
    }
}

void f(const string &s) {
    stack<int> stk;
    auto v=root;
    for(int i=0;i<s.size();i++) {
        stk.push(i);
        while(v!=root && !v->nxt[s[i]]) v=v->fail;
        if(v->nxt[s[i]]) v=v->nxt[s[i]];
        if(v->id!=-1) while(!stk.empty() && stk.top()>i-L[v->id]) A[stk.top()]=0, stk.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n;
    for(int i=0;i<n;i++) A[i]=1;

    string str; cin >> str;
    cin >> m;
    int dap=0;
    root=new Trie;
    for(int i=1;i<=m;i++) {
        string s; cin >> s;
        L[root->insert(s.c_str())]=s.length();
        if(i%100==0) {
            ahoy(), f(str);
            delete root;
            root=0;
            root=new Trie;
        }
    }
    if(root) ahoy(), f(str);
    cout << accumulate(A, A+303030,0);
    return 0;
}