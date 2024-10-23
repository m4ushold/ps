#include <bits/stdc++.h>
using namespace std;

bool f(vector<string> &v, int len) {
    vector<string> t;
    for(auto &i:v) t.push_back(i.substr(v[0].size()-len));
    sort(t.begin(),t.end());
    int n=v.size();
    t.erase(unique(t.begin(),t.end()),t.end());
    return n==t.size();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> v(m);
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        for(int j=0;j<s.size();j++) v[j]+=s[j];
    }
    int l=1, r=n;
    while(l<r) {
        int m=l+r>>1;
        if(f(v, m)) r=m;
        else l=m+1;
    }
    cout << n-r;
    return 0;
}