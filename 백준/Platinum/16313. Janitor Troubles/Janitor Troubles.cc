#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double a,b,c,d; cin >> a >> b >> c >> d;
    double s = (a+b+c+d)/2;
    cout << fixed << setprecision(12) << sqrt((s-a) * (s-b) * (s-c) * (s-d));
    return 0;
}