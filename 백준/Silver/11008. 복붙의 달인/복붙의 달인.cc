#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s,p; cin >> s >> p;
        int dap=0, i=0;
        while(i<s.size()) {
            i += s.substr(i,p.size()) == p ? p.size() : 1;
            dap++;
        }
        cout << dap << "\n";
    }
    return 0;
}