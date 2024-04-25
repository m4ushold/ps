#include <bits/stdc++.h>
using namespace std;

int id_cnt=0;

struct Trie {
    const static int sz=2;
    // map<char,Trie*> nxt; Trie *fail;
    Trie *nxt[sz], *fail;
    int id;
    Trie() : id(-1), fail(0) { nxt[0]=nxt[1]=0; }
    ~Trie() { for(int i=0;i<sz;i) if(nxt[i]) delete nxt[i]; }
    int insert(const char *s) {
        if(*s==0) return id == -1 ? id=++id_cnt : id;
        if(!nxt[*s-'0']) nxt[*s-'0']=new Trie();
        return nxt[*s-'0']->insert(s+1);
    }
} *root;

void ahoy() {
    queue<Trie*> q; q.push(root);
    root->fail=root;
    while(!q.empty()) {
        auto v=q.front(); q.pop();
        for(int i=0;i<v->sz;i++) if(v->nxt[i]) {
            if(v==root) v->nxt[i]->fail=root;
            else {
                auto t=v->fail;
                while(t!=root && !t->nxt[i]) t=t->fail;
                if(t->nxt[i]) t=t->nxt[i];
                v->nxt[i]->fail=t;
            }
            if(v->nxt[i]->id==-1) v->nxt[i]->id=v->nxt[i]->fail->id;
            q.push(v->nxt[i]);
        }
    }
}

vector<int> GetFail(const vector<int> &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> KMP(const vector<int> &s, const vector<int> &p){
    int n = s.size(), m = p.size();
    vector<int> fail = GetFail(p), ret;
    for(int i=0, j=0; i<s.size(); i++){
        while(j && s[i] != p[j]) j = fail[j-1];
            if(s[i] == p[j]){
            if(j + 1 == m) ret.push_back(i-m+1), j = fail[j];
            else j++;
        }
    }
    return ret;
}

int HP, WP, HM, WM, A[2020][2020];

void find(vector<string> &m) {
    for(int i=0;i<HM;i++) {
        auto v=root;
        for(int j=0;j<WM;j++) {
            while(v!=root && !v->nxt[m[i][j]-'0']) v=v->fail;
            if(v->nxt[m[i][j]-'0']) v=v->nxt[m[i][j]-'0'];
            A[i][j]=v->id;
        }
    }
}

char f(char c) { return c=='o' ? '0' : '1'; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> HP >> WP >> HM >> WM;
    vector<string> p(HP), m(HM);
    for(auto &i:p) {
        cin >> i;
        for(char &c:i) c=f(c);
    }
    for(auto &i:m) {
        cin >> i;
        for(char &c:i) c=f(c);
    }

    root=new Trie;
    vector<int> pp;
    for(auto i:p) pp.push_back(root->insert(i.c_str()));
    ahoy(), find(m);

    int dap=0;
    vector<int> v;
    for(int j=0;j<WM;j++) {
        v.clear();
        for(int i=0;i<HM;i++) v.push_back(A[i][j]);
        dap+=KMP(v,pp).size();
    }
    cout << dap;
    return 0;
}