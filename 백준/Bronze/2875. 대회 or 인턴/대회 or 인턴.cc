#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    while(k--) n/2>=m?--n:--m;
    cout << min(n/2,m);
    return 0;
}