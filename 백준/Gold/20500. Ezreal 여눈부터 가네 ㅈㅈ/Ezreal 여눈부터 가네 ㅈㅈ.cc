#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int N, D[3][2020];

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	D[0][2]=1, D[1][2]=1;
    for(int i=3;i<=N;i++) {
        D[0][i]=(D[2][i-1]+D[1][i-1])%MOD;
        D[1][i]=(D[2][i-1]+D[0][i-1])%MOD;
        D[2][i]=(D[0][i-1]+D[1][i-1])%MOD;
    }
	cout << D[0][N];
	return 0;
}