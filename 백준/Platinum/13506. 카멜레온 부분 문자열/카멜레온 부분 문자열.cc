#include <bits/stdc++.h>
using namespace std;

vector<int> GetFail(const string &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> KMP(const string &s, const string &p){
    int n = s.size(), m = p.size();
    vector<int> fail = GetFail(p), ret;
    for(int i=0, j=0; i<s.size(); i++){
        while(j && s[i] != p[j]) j = fail[j-1];
            if(s[i] == p[j]){
            if(j + 1 == m) ret.push_back(i-m+1), j = fail[j];
            else j++;
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    auto fail = GetFail(s);
    int n = s.size(), mx=fail.back();
    while(mx) {
        for(int i=1;i<n-1;i++) {
            if(fail[i] == mx) {
                cout << s.substr(0, mx);
                return 0;
            }
        }
        mx=fail[mx-1];
    }
    cout << -1;
    return 0;
}