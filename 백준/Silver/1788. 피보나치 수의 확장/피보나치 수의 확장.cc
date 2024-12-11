#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9;
int N, F[1010101]={0,1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=2;i<=abs(N);i++) F[i] = (F[i-1] + F[i-2])%MOD;
    int dap = F[abs(N)] * (N<0 && (~abs(N)&1) ? -1 : 1);
    cout << ((dap>0)-(dap<0)) << '\n' << abs(dap);
	return 0;
}