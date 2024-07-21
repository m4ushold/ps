#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int e, f, c; cin >> e >> f >> c;
    int a=e+f, dap=0;
    while (a >= c) {
        int t=a/c;
        dap+=t, a=t+(a%c);
    }
    cout << dap;
    return 0;
}