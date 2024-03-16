#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int cnt=0;
    for(char c:s) cnt+=c=='o'?1:2;
    cout << cnt;
    return 0;
}