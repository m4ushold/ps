#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    map<string,Trie> ch;
    void insert(const vector<string>& v, int i=0) {
        if(v.size()==i) return;
        auto it=ch.find(v[i]);
        if(it==ch.end()) it=ch.emplace(v[i], Trie()).first;
        it->second.insert(v,i+1);
    }
    void print(int d=0)
    {
        for(auto &[s,t]:ch) {
            cout << string(d*2,'-') << s << '\n';
            t.print(d+1);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Trie t;
    for(int i=0,k;i<n;i++) {
        vector<string> v;
        string s;
        cin >> k;
        for(int j=0;j<k;j++) cin >> s, v.push_back(s);
        t.insert(v);
    }
    t.print();
    return 0;
}