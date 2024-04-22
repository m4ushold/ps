#include <bits/stdc++.h>
using namespace std;


bool chk(string s) {
    for(int i=1;i<s.size()-1;i++) if(s[i]=='.') return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    if(n<=25) cout << s;
    else {
        string t=s.substr(11,s.size()-22);
        if(chk(t)) cout << s.substr(0,11) << "..." << s.substr(s.size()-11);
        else cout << s.substr(0,9) << "......" << s.substr(s.size()-10);
    }
    
    return 0;
}