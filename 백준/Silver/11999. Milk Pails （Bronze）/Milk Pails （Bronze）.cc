#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,mx=0; cin >> a >> b >> c;
    for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) {
        if(a*i+b*j <= c) mx=max(mx,a*i+b*j);
    }
    cout << mx;
    return 0;
}