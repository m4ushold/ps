#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<string> s;
    for(int i=0;i<n;i++) {
        string t; cin >> t;
        s.insert(t);
    }
    cout << s.size();
    return 0;
}