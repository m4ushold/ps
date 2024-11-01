#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Trie {
    Trie *nxt[2];
    Trie() { nxt[0]=nxt[1]=0; }
    void insert(const char *s) {
        if(*s==0) return ;
        if(!nxt[*s-'0']) nxt[*s-'0'] = new Trie();
        nxt[*s-'0']->insert(s+1);
    }
    int query(const char *s, int mn=0) {
        if(*s==0) return mn;
        int a=(*s-'0'), res;
        if(nxt[a]) mn<<=1, res=nxt[a]->query(s+1,mn);
        else mn=mn<<1|1, res=nxt[!a]->query(s+1,mn);
        return res;
    }
    ~Trie() { for(int i:{0,1}) delete nxt[i]; }
};

ll dnc(vector<int> &v, int l, int r, int bit) {
    if(r<=l || bit==-1) return 0;
    ll res=0, m=l;
    for(int i=l;i<=r;i++) {
        if(v[i]&(1<<bit)) break;
        m++;
    }
    
    if((r-m+1)>0 && (m-l)>0) {
        Trie t;
        int mn=1LL<<30;
        for(int i=l;i<=m-1;i++) t.insert(bitset<30>(v[i]).to_string().c_str());
        for(int i=m;i<=r;i++) mn=min(mn, t.query(bitset<30>(v[i]).to_string().c_str()));
        res+=mn;
    }
    res+=dnc(v, l, m-1, bit-1), res+=dnc(v, m, r, bit-1);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    cout << dnc(v,0,n-1,29);
    return 0;
}