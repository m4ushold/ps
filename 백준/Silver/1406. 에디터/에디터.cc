#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    stack<char> ls, rs;
    string s; cin >> s;
    for(char c:s) ls.push(c);

    int q; cin >> q;
    while(q--) {
        char a,b; cin >> a;
        if(a=='L' && !ls.empty()) rs.push(ls.top()), ls.pop();
        else if(a=='D' && !rs.empty()) ls.push(rs.top()), rs.pop();
        else if(a=='B' && !ls.empty()) ls.pop();
        else if(a=='P') cin >> b, ls.push(b);
    }
    while(!ls.empty()) rs.push(ls.top()), ls.pop();
    while(!rs.empty()) cout << rs.top(), rs.pop();
    
    return 0;
}