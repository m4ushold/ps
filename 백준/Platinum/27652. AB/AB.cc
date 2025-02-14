#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Trie {
    Trie *ch[26];
    int key, cnt=0;
    Trie() { fill(ch,ch+26,nullptr); key=-1, cnt=0; }
    void insert(const char *s, int id=0) {
        cnt++;
        if(*s==0) {key=id; return;}
        if(!ch[*s-'a']) ch[*s-'a'] = new Trie();
        ch[*s-'a']->insert(s+1, id);
    }
    void Delete(const char *s) {
        cnt--;
        if(*s==0) return;
        ch[*s-'a']->Delete(s+1);
    }
    int find(const char *s, vector<int> &v) {
        v.push_back(cnt);
        if(*s==0) return key;
        if(!ch[*s-'a']) {return -1;}
        else return ch[*s-'a']->find(s+1, v);
    }
    ~Trie() { for(int i=0;i<26;i++) if(ch[i]) delete ch[i]; }
} A, B;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while(q--) {
        string op,t,s;
        cin >> op >> t;
        if(op == "add") {
            cin >> s;
            if(t == "A") A.insert(s.c_str());
            else reverse(s.begin(),s.end()), B.insert(s.c_str());
        } else if(op == "delete") {
            cin >> s;
            if(t == "A") A.Delete(s.c_str());
            else reverse(s.begin(),s.end()), B.Delete(s.c_str());
        } else {
            vector<int> u,v;
            A.find(t.c_str(), u);
            reverse(t.begin(),t.end());
            B.find(t.c_str(), v);
            while(u.size() <= t.size()) u.push_back(0);
            while(v.size() <= t.size()) v.push_back(0);
            reverse(v.begin(),v.end());

            ll cnt=0;
            for(int i=1;i<t.size();i++) cnt+=u[i]*v[i];
            cout << cnt << '\n';
        }
    }
    return 0;
}