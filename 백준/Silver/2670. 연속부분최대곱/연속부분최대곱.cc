#include <bits/stdc++.h>
using namespace std;

double D[10101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<double> v(n);
    for(auto &i:v) cin >> i;
    double dap=0;
    for(int i=1;i<=n;i++) {
        D[i]=max(v[i-1], D[i-1]*v[i-1]);
        dap=max(dap, D[i]);
    }
    cout << fixed << setprecision(3) << dap;
	return 0;
}