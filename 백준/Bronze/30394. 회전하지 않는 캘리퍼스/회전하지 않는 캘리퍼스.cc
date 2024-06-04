#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, mn=numeric_limits<int>::max(), mx=numeric_limits<int>::min();
    cin >> n;
    for(int i=0,x,y;i<n;i++) cin >> x >> y, mn=min(mn, y), mx=max(mx, y);
    cout << mx-mn;
    return 0;
}