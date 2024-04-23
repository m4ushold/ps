#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *nxt[2];
    int key;
    Trie() { nxt[0]=nxt[1]=0, key=0; }
    void insert(const char *s) {
        key++;
        if(*s==0) return ;
        if(!nxt[*s-'0']) nxt[*s-'0'] = new Trie();
        nxt[*s-'0']->insert(s+1);
    }
    void remove(const char *s) {
        key--;
        if(*s==0) return ;
        if(nxt[*s-'0']) nxt[*s-'0']->remove(s+1);
    }
    void query(const char *s, string& res) {
        if(*s==0) return ;
        int a=(*s-'0')^1;
        if(nxt[a] && nxt[a]->key) res+='1', nxt[a]->query(s+1,res);
        else res+='0', nxt[!a]->query(s+1,res);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Trie t;
    t.insert(bitset<32>(0).to_string().c_str());
    for(int i=0;i<n;i++) {
        int a,b; cin >> a >> b;
        if(a==1) t.insert(bitset<32>(b).to_string().c_str());
        else if(a==2) t.remove(bitset<32>(b).to_string().c_str());
        else {
            string s;
            t.query(bitset<32>(b).to_string().c_str(), s);
            cout << stoi(s,0,2) << '\n';
        }
    }
    return 0;
}