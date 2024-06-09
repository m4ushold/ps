#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s && s!="#") {
        int y,m,d; cin >> y >> m >> d;
        tuple<int,int,int> t={y,m,d}, a={31,4,30};
        cout << (t>a ? "?" : s) << ' ' << (t>a ? y-30 : y) << ' ' << m << ' ' << d << '\n';
    }
    return 0;
}