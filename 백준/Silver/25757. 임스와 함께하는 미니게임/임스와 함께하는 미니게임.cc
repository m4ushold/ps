#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; char c; cin >> n >> c;
    set<string> s;
    while(n--) {
        string t; cin >> t;
        s.insert(t);
    }
    if(c=='Y')n=1;
    else if(c=='F')n=2;
    else n=3;
    cout << s.size()/n;
    return 0;
}