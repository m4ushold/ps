#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int w,h,p,q,t; cin >> w >> h >> p >> q >> t;
    p+=t, q+=t, p%=2*w, q%=2*h;
    if(p > w) p=w*2-p;
    if(q > h) q=h*2-q;
    cout << p << ' ' << q;
    return 0;
}