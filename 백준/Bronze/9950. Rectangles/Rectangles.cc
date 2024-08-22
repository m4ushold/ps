#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    while (cin >> a >> b >> c && (a||b)) {
        if(!a) a=c/b;
        if(!b) b=c/a;
        if(!c) c=a*b;
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}