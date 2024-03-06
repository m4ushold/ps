#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin,s);
    if(s[0]=='\"' && s.back()=='\"' && s.size()>2) cout << s.substr(1,s.size()-2);
    else cout << "CE";
    return 0;
}