#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; string s;
    cin >> n >> s;
    int ss=0, tt=0;
    for(char c:s) c=='s'?ss++:tt++;
    for(int i=0;i<n;i++) {
        if(ss==tt) {cout << s.substr(i); break;}
        s[i]=='s'?ss--:tt--;
    }
    return 0;
}