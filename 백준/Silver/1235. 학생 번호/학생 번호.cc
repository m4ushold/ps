#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    for(auto &s:v) cin >> s, reverse(s.begin(),s.end());
    for(int i=1;i<=v[0].size();i++) {
        set<string> st;
        for(auto s:v) st.insert(s.substr(0,i));
        if(st.size()==n) return cout << i, 0;
    }
    return 0;
}