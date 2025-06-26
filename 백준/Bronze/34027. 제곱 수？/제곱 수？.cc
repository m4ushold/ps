#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int s = sqrt(n);
        cout << (s*s == n) << '\n';
    }
    return 0;
}