#include <bits/stdc++.h>
using namespace std;

int f(int a) { return a*a*a*a*a; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int dap=0;
    for(char c:s) dap+=f(c-'0');
    cout << dap;
    return 0;
}