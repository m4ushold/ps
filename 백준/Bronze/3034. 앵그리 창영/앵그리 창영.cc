#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,w,h; cin >> n >> w >> h;
    while(n--) {
        int a; cin >> a;
        cout << (a*a<=w*w+h*h ? "DA\n" : "NE\n");
    }
    return 0;
}