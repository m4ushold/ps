#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int cnt=1;
        for(int i=1;i<s.size();i++) {
            if(s[i-1]!=s[i]) cout << cnt << s[i-1], cnt=1;
            else cnt++;
        }
        cout << cnt << s.back() << '\n';
    }
    return 0;
}