#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int a=10;
    for(int i=1;i<s.size();i++) a+=s[i-1]==s[i]?5:10;
    cout << a;
    return 0;
}