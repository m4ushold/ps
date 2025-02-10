#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n<=2) return cout << -1, 0;
    int y=1;
    for(int i=1;i<=n;i++) cout << i << ' ' << y << '\n', y+=i;
    return 0;
}