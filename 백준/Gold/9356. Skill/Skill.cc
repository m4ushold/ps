#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll N, D[101010][11];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=9;i++) D[1][i]=1;
    for(int i=2;i<=100'000;i++) {
        for(int j=0;j<=9;j++) D[i][j]=(D[i][j-1] + D[i-1][j])%MOD;
    }

    int t; cin >> t;
    while(t--) cin >> N, cout << D[N+1][9] << '\n';
    return 0;
}