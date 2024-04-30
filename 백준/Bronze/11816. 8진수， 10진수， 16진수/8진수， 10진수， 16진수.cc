#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    if(s[0]=='0' && s[1]=='x') cout << stoi(s.substr(2),0,16);
    else if(s[0]=='0') cout << stoi(s.substr(1),0,8);
    else cout << s;
    return 0;
}