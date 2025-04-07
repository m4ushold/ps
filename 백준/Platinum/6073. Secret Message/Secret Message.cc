#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie *ch[2];
    int end,sum;
    Trie() { fill(ch,ch+2,nullptr); end=0,sum=0; }
    void insert(const char *s) {
        sum++;
        if(*s==0) {end++;return;}
        if(!ch[*s-'0']) ch[*s-'0'] = new Trie();
        ch[*s-'0']->insert(s+1);
    }
    int find(const char *s) {
        if(*s==0) return sum;
        if(!ch[*s-'0']) return end;
        return end + ch[*s-'0']->find(s+1);
    }
    ~Trie() { for(int i=0;i<2;i++) if(ch[i]) delete ch[i]; }
} T;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for(int i=0,x,b;i<n;i++) {
        cin >> x;
        string s;
        while(x--) cin >> b, s+='0'+b;
        T.insert(s.c_str());
    }
    for(int i=0,x,b;i<m;i++) {
        cin >> x;
        string s;
        while(x--) cin >> b, s+='0'+b;
        cout << T.find(s.c_str()) << '\n';
    }
    return 0;
}