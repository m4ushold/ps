#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int s,c,o,n; cin >> s >> c >> o >> n;
    cout << min((s+n)/3, (c+2*o)/6);
    return 0;
}