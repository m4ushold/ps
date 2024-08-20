#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    if((~a&1) && (~b&1) && (~c&1)) cout << a*b*c;
    else {
        int ret=1;
        if(a&1) ret*=a;
        if(b&1) ret*=b;
        if(c&1) ret*=c;
        cout << ret;
    }
    return 0;
}