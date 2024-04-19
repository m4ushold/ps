#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << (s.back()&1 ? "odd\n" : "even\n");
    }
    return 0;
}