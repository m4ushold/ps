#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll a,b,c; cin >> a >> b >> c;
    // a^x + b^x = c^x
    // fermat's last theorem - 1,2만 확인
    if(a + b == c) cout << 1;
    else if(a*a + b*b == c*c) cout << 2;
    else cout << -1;
    return 0;
}