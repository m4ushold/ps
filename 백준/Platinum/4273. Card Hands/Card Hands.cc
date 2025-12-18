#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

struct Trie {
    map<string,Trie*> nxt;
    Trie() { }
    int insert(vector<string> &v, int i) {
        if(i == v.size()) return 0;
        int cnt=0;
        if(!nxt[v[i]]) nxt[v[i]] = new Trie(), cnt++;
        return cnt + nxt[v[i]]->insert(v,i+1);
    }
};

void sol(int n) {
    Trie t;
    int ans=0;
    for(int i=0;i<n;i++) {
        int k; cin >> k;
        vector<string> v(k);
        for(auto &s:v) cin >> s;
        reverse(all(v));
        ans += t.insert(v,0);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while(cin >> n && n) sol(n);
    return 0;
}