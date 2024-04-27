#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int F[101];

bool uf(string s) {
    for(int i=1;i<s.size();i++) if(s[i-1]==' ' && !F[toupper(s[i])]) {
        F[toupper(s[i])]=1;
        if(i+1!=s.size()) cout << s.substr(1,i-1) << "[" << s[i] << "]" << s.substr(i+1) << '\n';
        else cout << s.substr(1,i-1) << "[" << s[i] << "]\n";
        return 1;
    }
    return 0;
}

bool u(string s) {
    for(int i=1;i<s.size();i++) if(isalpha(s[i]) && !F[toupper(s[i])]) {
        F[toupper(s[i])]=1;
        if(i+1!=s.size()) cout << s.substr(1,i-1) << "[" << s[i] << "]" << s.substr(i+1) << '\n';
        else cout << s.substr(1,i-1) << "[" << s[i] << "]\n";
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s; getline(cin, s);
        s=" "+s;
        if(uf(s)) continue;
        if(u(s)) continue;
        cout << s.substr(1) << '\n';
    }
    return 0;
}