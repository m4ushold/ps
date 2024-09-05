#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a,b,c,p; cin >> a >> b >> c >> p;
        a%=p, b%=p, c%=p;
        cout << (a+b+c == max({a,b,c})) << '\n';
    }
    return 0;
}