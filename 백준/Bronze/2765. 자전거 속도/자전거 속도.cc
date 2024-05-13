#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    double a,c; int b, i=1;
    while(cin >> a >> b >> c && b) {
        cout << fixed << setprecision(2) << "Trip #" << i++ << ": " << a*b*M_PI/5280.0/12.0 << ' ' << a*b*M_PI/5280.0/12.0/c*60*60 << '\n';
    }
    return 0;
}