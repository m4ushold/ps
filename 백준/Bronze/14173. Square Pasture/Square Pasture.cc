#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> x(4),y(4);
    for(int i=0;i<4;i++) cin >> x[i] >> y[i];
    int xx=max(x[1],x[3])-min(x[0],x[2]);
    int yy=max(y[1],y[3])-min(y[0],y[2]);
    cout << max(xx,yy)*max(xx,yy);
    return 0;
}