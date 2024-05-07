#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    int dap=a*2;
    if(c>1) dap+=2*b+3, c-=2;
    dap+=c/2*3;
    cout << dap;
    return 0;
}