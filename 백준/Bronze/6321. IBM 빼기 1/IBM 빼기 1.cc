#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        cout << "String #" << i << '\n';
        string s; cin >> s;
        for(char c:s) cout << (char)(c=='Z' ? 'A' : c+1);
        cout << "\n\n";
    }
    return 0;
}