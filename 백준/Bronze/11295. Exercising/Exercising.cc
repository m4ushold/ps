#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1, l;
    while (cin >> l && l) {
        int n; cin >> n;
        cout << "User " << t++ << '\n';
        for (int i = 0; i < n; i++) {
            int s; cin >> s;
            cout << fixed << setprecision(5) << s*l/100000.0 << '\n';
        }
    }
    return 0;
}