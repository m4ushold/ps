#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char,Trie*> m;
    int key;
    Trie() { key=0; }
    bool insert(const char *s, int id=1) {
        if(*s==0) {key=id; return 1;}
        if(key) return 0;
        if(!m[*s]) m[*s]=new Trie();
        return m[*s]->insert(s+1,id);
    }
    ~Trie() { for(auto [c,t]:m) delete t; }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        Trie trie;
        int n; cin >> n;
        vector<string> v(n);
        for(auto &i:v) cin >> i;
        sort(v.begin(),v.end());
        
        int f=1;
        for(auto i:v) f&=trie.insert(i.c_str());
        cout << (f?"YES\n":"NO\n");
    }
    return 0;
}