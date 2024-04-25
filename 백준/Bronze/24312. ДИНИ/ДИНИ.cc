#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(4);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int dap=1e9;
    for(int i=1;i<15;i++) {
        int a=0;
        for(int j=0;j<4;j++) a += ((i>>j)&1) ? v[j] : -v[j];
        dap=min(dap, abs(a));
    }
    cout << dap;
    return 0;
}