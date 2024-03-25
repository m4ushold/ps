#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n==1) cout << "0\n";
        else if(n&1) cout << 1 << string(n-2,'2') << "1\n";
        else cout << string(n,'1') << '\n';
    }
    return 0;
}