#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<char> v(n);
    for(char &c:v) cin >> c;
    int dap=0;
    for(int i=0;i<n;i++) {
        char c; cin >> c;
        if(c==v[i]) dap++;
    }
    cout << dap;

    return 0;
}