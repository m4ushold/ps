#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *ch[26];
    int key;
    Trie() { fill(ch,ch+26,nullptr); key=-1; }
    void insert(const char *s, int id=0) {
        if(*s==0) {key=id; return;}
        if(!ch[*s-'a']) ch[*s-'a'] = new Trie();
        ch[*s-'a']->insert(s+1, id);
    }
    int find(const char *s) {
        if(*s==0) return 1;
        if(!ch[*s-'a']) return 0;
        else return ch[*s-'a']->find(s+1);
    }
    ~Trie() { for(int i=0;i<26;i++) if(ch[i]) delete ch[i]; }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    Trie t;
    string s; 
    while(n--) cin >> s, t.insert(s.c_str());
    int cnt=0;
    while(m--) cin >> s, cnt+=t.find(s.c_str());
    cout << cnt;
    return 0;
}