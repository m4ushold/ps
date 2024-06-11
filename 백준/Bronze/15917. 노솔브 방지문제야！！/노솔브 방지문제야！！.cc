#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        cout << (__popcount(n)==1) << '\n';
    }
    return 0;
}