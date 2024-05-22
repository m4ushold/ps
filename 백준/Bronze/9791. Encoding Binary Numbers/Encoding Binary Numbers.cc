#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s && s!="0") {
        int cnt=1;
        for(int i=1;i<s.size();i++) {
            if(s[i-1]!=s[i]) cout << cnt << s[i-1], cnt=1;
            else cnt++;
        }
        cout << cnt << s.back();
        cout << '\n';
    }
    return 0;
}