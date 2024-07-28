#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int r,w,l,i=1;
    while(cin >> r && r && cin >> l >> w) {
        int a=4*r*r, b=l*l+w*w;
        cout << "Pizza " << i++ << " ";
        if(a<b) cout << "does not fit on the table.\n";
        else cout << "fits on the table.\n";
    }
    return 0;
}