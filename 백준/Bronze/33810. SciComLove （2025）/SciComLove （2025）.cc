#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s,t="SciComLove";
    cin >> s;
    int cnt=0;
    for(int i=0;i<t.size();i++) cnt+=s[i]!=t[i];
    cout << cnt;
    return 0;
}