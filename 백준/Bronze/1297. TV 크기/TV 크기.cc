#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int d, h, w; cin >> d >> h >> w;
    double t=atan(1.0*h/w);
    cout << (int)(d*sin(t)) << ' ' << (int)(d*cos(t));
    return 0;
}