#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *nxt[4];
    vector<int> out;
    Trie* fail;
    int term;
    Trie() : term(-1) { memset(nxt,0,sizeof nxt); }
    ~Trie() { for(int i=0;i<4;i++) if(nxt[i]) delete nxt[i]; }
    void insert(const char *s, int id=1) {
        if(*s==0) {term=id; return;}
        if(!nxt[*s-'a']) nxt[*s-'a'] = new Trie();
        nxt[*s-'a']->insert(s+1, id);
    }
};

void build(Trie *root) {
    queue<Trie*> q;
    root->fail=root, q.push(root);
    while(!q.empty()) {
        auto v=q.front(); q.pop();
        for(int c=0;c<4;c++) {
            Trie *u=v->nxt[c];
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
        while(v!=root && !v->nxt[s[i]-'a']) v=v->fail;
        if(v->nxt[s[i]-'a']) v=v->nxt[s[i]-'a'];
        ret+=v->out.size();
    }
    return ret;
}

char f(char a) {
    if(a=='A') return 'a';
    else if(a=='C') return 'b';
    else if(a=='G') return 'c';
    return 'd';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    
    while(t--) {
        int n, m; cin >> n >> m;
        string a,b; cin >> a >> b;
        for(char &c:a) c=f(c);
        for(char &c:b) c=f(c);

        Trie *root=new Trie;
        root->insert(b.c_str());
        for(int i=0;i<=m;i++) for(int j=i+2;j<=m;j++) {
            reverse(b.begin()+i,b.begin()+j);
            root->insert(b.c_str());
            reverse(b.begin()+i,b.begin()+j);
        }
        build(root);
        cout << find(a,root) << '\n';
        delete root;
    }
    return 0;
}