#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *nxt[2];
    int cnt;
    Trie() : cnt(0) { nxt[0]=nxt[1]=0; }
    ~Trie() { for(int i:{0,1}) if(nxt[i]) delete nxt[i]; }
    int count(const char *s) {
        if(*s==0) return cnt;
        if(!nxt[*s-'0']) return 0;
        return nxt[*s-'0']->count(s+1);
    }
    int insert(const char *s) {
        cnt++;
        if(*s==0) return cnt;
        if(!nxt[*s-'0']) nxt[*s-'0'] = new Trie();
        return nxt[*s-'0']->insert(s+1);
    }
    int max(string &res) {
        if(nxt[1] && nxt[1]->cnt) {res+='1'; return nxt[1]->max(res);}
        if(nxt[0] && nxt[0]->cnt) {res+='0'; return nxt[0]->max(res);}
        return cnt;
    }
    int min(string &res) {
        if(nxt[0] && nxt[0]->cnt) {res+='0'; return nxt[0]->min(res);}
        if(nxt[1] && nxt[1]->cnt) {res+='1'; return nxt[1]->min(res);}
        return cnt;
    }
    void remove(const char *s) {
        cnt--;
        if(*s==0) return ;
        nxt[*s-'0']->remove(s+1);
    }
    void max(const char *s, string& res) {
        if(*s==0) return ;
        int a=(*s-'0')^1;
        if(nxt[a] && nxt[a]->cnt) res+='1', nxt[a]->max(s+1,res);
        else res+='0', nxt[!a]->max(s+1,res);
    }
    void min(const char *s, string& res) {
        if(*s==0) return ;
        int a=(*s-'0');
        if(nxt[a] && nxt[a]->cnt) res+='0', nxt[a]->min(s+1,res);
        else res+='1', nxt[!a]->min(s+1,res);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        Trie t;
        set<int> st;
        int n, q; cin >> n >> q;
        for(int i=0,a;i<n;i++) {
            cin >> a;
            if(st.insert(a).second) t.insert(bitset<32>(a).to_string().c_str());
        }

        while(q--) {
            int a,v; cin >> a;
            string s;
            if(a==1) cin >> v, t.min(bitset<32>(v).to_string().c_str(),s), cout << stoi(s,0,2) << '\n';
            else if(a==2) cin >> v, t.max(bitset<32>(v).to_string().c_str(),s), cout << stoi(s,0,2) << '\n';
            else if(a==3) {
                cin >> v;
                if(st.insert(v).second) t.insert(bitset<32>(v).to_string().c_str());
                cout << st.size() << '\n';
            }
            else if(a==4) t.min(s), cout << stoi(s,0,2) << '\n', t.remove(s.c_str()), st.erase(stoi(s,0,2));
            else t.max(s), cout << stoi(s,0,2) << '\n', t.remove(s.c_str()), st.erase(stoi(s,0,2));
        }
    }
    return 0;
}