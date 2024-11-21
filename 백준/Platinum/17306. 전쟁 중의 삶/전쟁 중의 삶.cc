#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Trie {
    Trie *ch[2];
    ll key, sz;
    Trie() : sz(1) { fill(ch,ch+2,nullptr); key=-1; }
    void insert(const char *s, int id=0) {
        if(*s==0) {key=id; return;}
        if(!ch[*s-'0']) ch[*s-'0'] = new Trie();
        ch[*s-'0']->insert(s+1, id);
        sz = 1;
        for(int i:{0,1}) if(ch[i]) sz+=ch[i]->sz;
    }
    int cnt() {
        static int a=0;
        if(key == -1 && (!ch[0] || !ch[1])) {
            a++;
            for(auto i:{ch[0], ch[1]}) if(i) return i->cnt();
        }
        return a;
    }
    ~Trie() { for(int i=0;i<2;i++) if(ch[i]) delete ch[i]; }
} trie;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) {
        cin >> i;
        string s = bitset<50>(i).to_string();
        reverse(s.begin(),s.end());
        while(s.back()=='0') s.pop_back();
        reverse(s.begin(),s.end());
        trie.insert(s.c_str());
    }
    cout << trie.sz-trie.cnt();
    return 0;
}