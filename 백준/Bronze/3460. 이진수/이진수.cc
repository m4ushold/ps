#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=0;i<31;i++) if(n & (1<<i)) cout << i << " ";
        cout << '\n';
    }
    return 0;
}