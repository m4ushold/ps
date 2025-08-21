#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char,Trie*> m;
    int key, cnt;
    Trie() { key=-1, cnt=0; }
    void insert(const char *s, int id=0) {
        cnt++;
        if(*s==0) {key=id; return ;}
        if(!m[*s]) m[*s]=new Trie();
        m[*s]->insert(s+1,id);
    }
    int dfs(int d=0) {
        if(cnt == 1) return d;
        int res=0;
        for(auto [i,j]:m) {
            res+=j->dfs(d+1);
        }
        return res;
    }
    ~Trie() { for(auto [c,t]:m) delete t; }
};

void sol(int tc) {
    int n,l; cin >> n >> l;
    Trie t;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        t.insert(s.c_str());
    }
    cout << t.dfs();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}