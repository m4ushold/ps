#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int x=0,y=0;
    vector<pair<int,int>> v(n);
    for(auto &[a,b]:v) cin >> a >> b, x+=a, y+=b;
    cout << x << ' ' << y << endl;
    double mn = 1e9;
    for(auto [a,b]:v) mn=min(mn, hypot(x-a,y-b));
    cout << fixed << setprecision(2) << mn;
    return 0;
}