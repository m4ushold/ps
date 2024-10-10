#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=2;i<=n/2+1;i++) cout << i << ' ' << -i << ' ';
    if(n&1) cout << n << ' ' << 1;
    else cout << 0;
    return 0;
}