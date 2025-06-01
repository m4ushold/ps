#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9+9;
int D[101010][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    D[1][1] = D[2][2] = D[3][1] = D[3][2] = D[3][3] = 1;
    for(int i=4;i<101010;i++) {
        D[i][1] = (D[i-1][2] + D[i-1][3]) % mod;
        D[i][2] = (D[i-2][1] + D[i-2][3]) % mod;
        D[i][3] = (D[i-3][1] + D[i-3][2]) % mod;
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << accumulate(D[n], D[n]+4, 0LL) % mod << '\n';
    }
    return 0;
}