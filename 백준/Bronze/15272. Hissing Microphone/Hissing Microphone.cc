#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    for(int i=0;i<s.size();i++) {
        if(s[i] == 's' && s[i+1] == 's') return cout << "hiss", 0;
    }
    cout << "no hiss";
    return 0;
}