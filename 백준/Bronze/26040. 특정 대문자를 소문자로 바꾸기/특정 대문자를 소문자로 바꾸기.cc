#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int F[202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    char c;
    while(cin >> c) F[c]=1;

    for(char &c:s) c=F[c] ? tolower(c) : c;
    cout << s;
    
    return 0;
}