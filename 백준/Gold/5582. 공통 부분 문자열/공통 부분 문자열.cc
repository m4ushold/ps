#include <bits/stdc++.h>
using namespace std;

int D[4001][4001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    string a,b; cin >> a >> b;
    int dap=0;
	for(int i=1; i<=a.size(); i++) {
		for(int j=1; j<=b.size(); j++) {
			if(a[i-1] == b[j-1]) {
				D[i][j] = D[i-1][j-1] + 1;
				dap = max(dap,D[i][j]);
			}
			else D[i][j] = 0;
		}
	}
	cout << dap;
    return 0;
}