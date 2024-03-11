#include <bits/stdc++.h>
using namespace std;

bool p(string s) {
    for(int i=0;i<s.size()/2;i++) {
        if(s[i]!=s[s.size()-1-i]) return 0;
    }
    return 1;
}

pair<bool,string> f(vector<string> &v) {
    for(int i=0;i<v.size();i++) for(int j=0;j<v.size();j++) if(i!=j) {
        if(p(v[i]+v[j])) return {1,v[i]+v[j]};
        if(p(v[j]+v[i])) return {1,v[j]+v[i]};
    }
    return {0,""};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> v(n);
        for(auto &i:v) cin >> i;
        auto [a,s]=f(v);
        if(a) cout << s << '\n';
        else cout << "0\n";
    }
    return 0;
}