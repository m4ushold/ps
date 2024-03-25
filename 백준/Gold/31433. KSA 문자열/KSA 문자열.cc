#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s,ksa="KSA"; cin >> s;
    int i=0, cnt=0, res=1e9;
    for(char c:s) c==ksa[i%3] ? ++i : ++cnt;
    cnt+=abs(i-(int)s.size());
    res=min(res,cnt);

    i=1, cnt=1;
    for(char c:s) c==ksa[i%3] ? ++i : ++cnt;
    cnt+=abs(i-(int)s.size());
    res=min(res,cnt);

    i=2, cnt=2;
    for(char c:s) c==ksa[i%3] ? ++i : ++cnt;
    cnt+=abs(i-(int)s.size());
    res=min(res,cnt);

    cout << res;
    return 0;
}