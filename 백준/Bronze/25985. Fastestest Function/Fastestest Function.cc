#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    double x,y; cin >> x >> y;
    x/=100, y/=100;
    cout << fixed << setprecision(12) << (1-y)/y*x/(1-x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}