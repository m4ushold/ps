#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--) {
        int r=0,g=0,b=0;
        for(int i=0,rr,gg,bb;i<10;i++) cin >> rr >> gg >> bb, r+=rr, g+=gg, b+=bb;
        r=(double)r/10+0.5, g=(double)g/10+0.5, b=(double)b/10+0.5;
        cout << r << ' ' << g << ' ' << b << '\n';
    }
    return 0;
}