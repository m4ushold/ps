#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s,res; cin >> s;
    res+=s[0];
    for(int i=1;i<s.size();i++) if(s[i]=='-') res+=s[i+1];
    cout << res;
    return 0;
}