#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    vector<pair<string,int>> v(n);
    for(auto &[s,i]:v) cin >> s >> i;
    map<string,pair<string,string>> res;
    int m; cin >> m;
    for(int i=0,x;i<m;i++) {
        string s; cin >> s >> x;
        sort(v.begin(),v.end(),[&x](pair<string,int> a, pair<string,int> b) {
            if(abs(a.second-x) == abs(b.second-x)) return a.first < b.first;
            return abs(a.second-x) <= abs(b.second-x);
        });
        res[s] = {v[0].first, v[1].first};
    }

    int q; cin >> q;
    string name;
    for(int i=0;i<q;i++) {
        string a,b,c; cin >> a >> b >> c;
        if(b != "-") cout << res[name].second << " yori mo " << res[name].first << '\n';
        else name = a, cout << "hai!\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}