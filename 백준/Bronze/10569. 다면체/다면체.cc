#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int v,e; cin >> v >> e;
        cout << 2-v+e << '\n';
    }
    return 0;
}