#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *nxt[2];
    Trie() { nxt[0]=nxt[1]=0; }
    void insert(const char *s) {
        if(*s==0) return ;
        if(!nxt[*s-'0']) nxt[*s-'0'] = new Trie();
        nxt[*s-'0']->insert(s+1);
    }
    void query(const char *s, string& res) {
        if(*s==0) return ;
        int a=(*s-'0')^1;
        if(nxt[a]) res+='1', nxt[a]->query(s+1,res);
        else res+='0', nxt[!a]->query(s+1,res);
    }
    ~Trie() { for(int i:{0,1}) delete nxt[i]; }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i], v[i]^=v[i-1];
        
        Trie t;
        for(int i=0;i<=n;i++) t.insert(bitset<32>(v[i]).to_string().c_str());
        int mx=0;
        for(int i=1;i<=n;i++) {
            string res="";
            t.query(bitset<32>(v[i]).to_string().c_str(),res);
            mx=max(mx,stoi(res,0,2));
        }
        cout << mx << '\n';
    }
    
    return 0;
}