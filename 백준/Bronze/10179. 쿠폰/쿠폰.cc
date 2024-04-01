#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        double n; cin >> n;
        cout << fixed << setprecision(2) << "$" << n*0.8 << '\n';
    }
    return 0;
}