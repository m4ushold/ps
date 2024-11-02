#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    for(int i=0;i<n-1;i++) {
        if(s[i+1]=='J') cout << s[i] << '\n';
    }
    return 0;
}