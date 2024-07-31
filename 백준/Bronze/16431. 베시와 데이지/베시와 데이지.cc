#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int b,bb,d,dd,j,jj; cin >> b >> bb >> d >> dd >> j >> jj;
    int d1 = max(abs(b-j), abs(bb-jj)), d2 = abs(d-j)+abs(dd-jj);
    if(d1 < d2) cout << "bessie";
    else if(d1 > d2) cout << "daisy";
    else cout << "tie";
    return 0;
}