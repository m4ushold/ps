#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    while(getline(cin,s) && s!="***") {
        reverse(s.begin(),s.end());
        cout << s << '\n';
    }
    return 0;
}