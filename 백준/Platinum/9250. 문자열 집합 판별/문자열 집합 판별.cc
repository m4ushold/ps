#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char,Trie*> nxt;
    vector<int> out;
    Trie* fail;
    int term;
    Trie() : term(-1) {}
    void insert(const char *s, int id=1) {
        if(*s==0) {term=id; return ;}
        if(!nxt[*s]) nxt[*s]=new Trie();
        nxt[*s]->insert(s+1,id);
    }
    ~Trie() { 
        for(auto [c,t]:nxt) delete t;
        nxt.clear();
    }
};

void build(Trie *root) {
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
            u->out=u->fail->out;
            if(u->term!=-1) u->out.push_back(u->term);
            q.push(u);
        }
    }
}

bool find(const string &s, Trie *root) {
    auto v=root;
    for(char c:s) {
        while(v!=root && !v->nxt[c]) v=v->fail;
        if(v->nxt[c]) v=v->nxt[c];
        if(v->out.size()) return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n;
    Trie *root=new Trie;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        root->insert(s.c_str());
    }
    build(root);

    cin >> m;
    for(int i=0;i<m;i++) {
        string s; cin >> s;
        cout << (find(s,root) ? "YES\n" : "NO\n");
    }
    return 0;
}