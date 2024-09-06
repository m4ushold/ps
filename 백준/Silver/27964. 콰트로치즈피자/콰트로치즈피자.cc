#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<string> st;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        if(s.size()>=6 && s.substr(s.size()-6)=="Cheese") st.insert(s);
    }
    if(st.size() > 3) cout << "yummy";
    else cout << "sad";
    return 0;
}