#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cout << "ABCDEFGHIJKL"[(n+8)%12] << (n+6)%10;
    return 0;
}