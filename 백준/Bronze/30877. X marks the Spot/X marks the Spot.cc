#include <bits/stdc++.h>
using namespace std;

void sol(int tc) {
    string s,t; cin >> s >> t;
    for(int i=0;i<s.size();i++) if(tolower(s[i]) == 'x') {
        if(islower(t[i])) t[i]=toupper(t[i]);
        cout << t[i];
        return;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}