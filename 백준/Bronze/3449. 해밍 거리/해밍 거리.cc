#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        int dap=0;
        for(int i=0;i<a.size();i++) dap+=a[i]!=b[i];
        cout << "Hamming distance is " << dap << ".\n";
    }
    return 0;
}