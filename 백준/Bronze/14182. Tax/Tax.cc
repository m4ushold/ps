#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n && n) {
        if(n <= 1'000'000) cout << n;
        else if(n <= 5'000'000) cout << (int)(0.9*n);
        else cout << (int)(0.8*n);
        cout << '\n';
    }
    return 0;
}