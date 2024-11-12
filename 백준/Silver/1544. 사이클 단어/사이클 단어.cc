#include <bits/stdc++.h>
using namespace std;

bool chk(unordered_set<string> &s, string str) {
    for(int i=0;i<str.size();i++) {
        if(s.count(str.substr(i) + str.substr(0,i))) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    unordered_set<string> s;
    int n; cin >> n;
    while(n--) {
        string str; cin >> str;
        if(chk(s, str)) s.insert(str);
    }
    cout << s.size();

    return 0;
}