#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll x,y,c; cin >> x >> y >> c;
    if(x==0 && y==0) cout << 0;
    else if((x*x+y*y) == (c*c)) cout << 1;
    else cout << max(2,(int)ceil(sqrt(x*x+y*y)/c));
    return 0;
}