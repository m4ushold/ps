#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, L, R, D[101][101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    D[1][1][1]=1;
    for(int n=2;n<=20;n++) for(int l=1;l<=n;l++) for(int r=1;r<=n;r++) {
        D[n][l][r] = (D[n-1][l-1][r] + D[n-1][l][r-1] + D[n-1][l][r]*(n-2));
    }
    while(t--) {
        cin >> N >> L >> R;
        cout << D[N][L][R] << '\n';
    }
    return 0;
}