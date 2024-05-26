#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n && n>0) {
        vector<pair<int,int>> v(n);
        int t=0, dap=0;
        for(auto &[a,b]:v) {
            cin >> a >> b;
            dap+=a*(b-t);
            t=b;
        }
        cout << dap << " miles\n";
    }
    return 0;
}