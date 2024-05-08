#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m-1;j++) cout << i*m+j+1 << ' ';
        cout << i*m+m << "\n";
    }
	return 0;
}