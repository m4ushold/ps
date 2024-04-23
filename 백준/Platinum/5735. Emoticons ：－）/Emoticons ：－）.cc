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

int find(const string &s, Trie *root) {
    int ret=0;
    auto v=root;
    for(int i=0;i<s.size();i++) {
        while(v!=root && !v->nxt[s[i]]) v=v->fail;
        if(v->nxt[s[i]]) v=v->nxt[s[i]];
        if(v->out.size()) ret++, v=root;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    while(cin >> n >> m && n) {
        cin.ignore();
        Trie *root=new Trie;
        string s;
        while(n--) getline(cin, s), root->insert(s.c_str());
        build(root);
        int cnt=0;
        while(m--) getline(cin, s), cnt+=find(s, root);
        cout << cnt << '\n';
        delete root;
    }
    return 0;
}