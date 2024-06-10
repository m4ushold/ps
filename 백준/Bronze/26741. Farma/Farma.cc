
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int x,y; cin >> y >> x;
    int a=(x-2*y)/2, b=y-a;
    cout << b << ' ' << a;
    return 0;
}