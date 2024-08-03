#include <bits/stdc++.h>
using namespace std;

string trans(string s) {
    if(s.size()<=1) return s;

    string t;
    for(int i=0;i<s.size();i++) {
        if(i==s.size()-1) t+=s[i];
        else if(s[i] == s[i+1]) {i++; continue;}
        else if(s.substr(i,2)=="BA" || s.substr(i,2)=="BC") {
            swap(s[i], s[i+1]);
            t+=s[i];
        } else t+=s[i];
    }
    return t;
}

void sol() {
    string a,b; cin >> a >> b;
    int n=max(a.size(),b.size());
    for(int i=0;i<n;i++) a=trans(a), b=trans(b);
    cout << (a==b ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}