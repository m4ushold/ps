#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    vector<pair<int,string>> v(6);
    for(int i=0;i<6;i++) {
        string s; cin >> s;
        int pt,pu,rt,ru,f; cin >> pt >> pu >> rt >> ru >> f;
        v.push_back({0.06*pt + 0.14*pu + 0.24*rt + 0.56*ru + 0.3*f, s});
    }
    sort(v.begin(),v.end(),greater<>());
    vector<int> ans(6);
    for(int i=0;i<n;i++) ans[i%6]++;
    for(int i=0;i<6;i++) if(v[i].second == "Taiwan") cout << ans[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}