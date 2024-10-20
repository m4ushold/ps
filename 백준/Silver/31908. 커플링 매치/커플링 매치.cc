#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string,vector<string>> m;
    while(n--) {
        string a,b; cin >> a >> b;
        m[b].push_back(a);
    }

    vector<pair<string,string>> v;
    for(auto [i,j]:m) if(i!="-") {
        if(j.size()==2) v.push_back({j.front(), j.back()});
    }
    cout << v.size() << '\n';
    for(auto [i,j]:v) cout << i << ' ' << j << '\n';
    return 0;
}