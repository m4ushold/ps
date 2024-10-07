#include <bits/stdc++.h>

#define int long long
using namespace std;

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> A(n);
        for (auto &i: A)cin >> i;
        int xr = 0;
        for (int s = 1; s < n; s++) {
            string i = A[s];
            int g = 0;
            if (i == "111")g = 2;
            if (i == "110" || i == "011")g = 1;
            xr ^= g;
        }
        cout << (xr ? "Yesyes\n" : "Nono\n");
    }
}