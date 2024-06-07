
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;
        cout << n/c+!!(n%c) << '\n';
    }
    return 0;
}