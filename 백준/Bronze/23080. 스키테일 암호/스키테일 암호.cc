#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin >> k;
    string s; cin >> s;
    for(int i=0;i<s.size();i+=k) cout << s[i];
    return 0;
}