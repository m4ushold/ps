#include <bits/stdc++.h>
using namespace std;

void sol() {
    double r; cin >> r;
    double dia = 2*(r + r*sqrt(3) + r*sqrt(2));
    double x = dia * 1 / sqrt(2);
    cout << fixed << setprecision(12) << x*x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}