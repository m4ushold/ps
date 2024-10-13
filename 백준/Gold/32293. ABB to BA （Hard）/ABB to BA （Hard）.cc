#include <bits/stdc++.h>
using namespace std;

void chk(stack<char> &s) {
    if(s.size() < 3) return;
    string tmp;
    tmp+=s.top(); s.pop();
    tmp+=s.top(); s.pop();
    tmp+=s.top(); s.pop();
    if(tmp == "BBA") {
        s.push('B');
        chk(s);
        s.push('A');
        return;
    }
    s.push(tmp[2]), s.push(tmp[1]), s.push(tmp[0]);
}

void sol() {
    int n; string s;
    cin >> n >> s;
    stack<char> stk;
    for(char c:s) {
        stk.push(c);
        chk(stk);
    }
    string tmp;
    while(stk.size()) tmp+=stk.top(), stk.pop();
    reverse(tmp.begin(),tmp.end());
    cout << tmp << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}