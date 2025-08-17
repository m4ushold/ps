#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    string s; cin >> s;
    for(int i=0;i<s.size();i++) {
        if(s[i] == 'O' && i && s[i-1] == 'P') cout << 'H';
        cout << s[i];
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}