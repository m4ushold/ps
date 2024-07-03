#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s) {
        int c=1, mx=0;
        for(int i=1;i<s.size();i++) s[i-1]==s[i] ? c++ : (mx=max(mx,c), c=1);
        cout << max(mx,c) << '\n';
    }
    return 0;
}