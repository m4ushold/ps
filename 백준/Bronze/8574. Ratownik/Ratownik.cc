#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, x, y, cnt=0; cin >> n >> k >> x >> y;
    for(int i=0,a,b;i<n;i++) cin >> a >> b, cnt+=hypot(x-a,y-b) > k;
    cout << cnt;
    return 0;
}