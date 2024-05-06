#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << "Do-it" << (s[s.size()/2-1]!=s[s.size()/2] ? "-Not\n" : "\n");
    }
    return 0;
}